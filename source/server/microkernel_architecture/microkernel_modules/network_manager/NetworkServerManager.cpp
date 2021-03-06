#include "NetworkServerManager.hpp"
#include "NetworkClient.hpp"
#include "MainController.hpp"
#include "_QFile.hpp"
#include <QByteArray>

//
// NetworkServer static attributes assignation
//
const QString NetworkServerManager::_ENCRYPTION_KEY_FILE = "server.key";
const QString NetworkServerManager::_ENCRYPTION_CERTIFICATE_FILE = "server.crt";
const QSsl::SslProtocol NetworkServerManager::_DEFAULT_PROTOCOL = QSsl::TlsV1_2;

//
// Construct network server
//
NetworkServerManager::NetworkServerManager(quint16 port)
    : ANetworkManager(false), _port(port), _server(this)
{
    qRegisterMetaType<QList<QSslError> >("QList<QSslError>");
}

//
// Destroy network server
//
NetworkServerManager::~NetworkServerManager()
{
    for (auto socketDescriptor : _clientSockets.keys())
    {
        delete _clientSockets[socketDescriptor];
        _clientSockets.remove(socketDescriptor);
    }
    delete _encryptionKey;
    delete _encryptionCertificate;
}

//
// Entry point
//
void NetworkServerManager::_run()
{
    connect(&_server, SIGNAL(hasIncomingConnection(qintptr)),
            this, SLOT(_incomingConnection(qintptr)));
    start();
}

//
// Initialize and start server
//
bool NetworkServerManager::start()
{
    qDebug() << Q_FUNC_INFO;

    if (!QSslSocket::supportsSsl())
    {
        qDebug() << " Error SSL is not available on this machine";
        return (false);
    }
    qDebug() << QSslSocket::sslLibraryVersionString();
    if (!_initEncryptionKey(_ENCRYPTION_KEY_FILE) ||
        !_initEncryptionCertificate(_ENCRYPTION_CERTIFICATE_FILE) ||
        !_listen(_port))
        return (false);
    return (true);
}

//
// Set peer input buffer pointer
//
void NetworkServerManager::_setPeerInputBuffer(InstructionBuffer *buffer, quint64 peerId)
{
    _clientIds[peerId]->setInputBuffer(buffer);
}

//
// Get peer input buffer pointer
//
InstructionBuffer *NetworkServerManager::_getPeerInputBuffer(quint64 peerId) const
{
    return _clientIds[peerId]->getInputBuffer();
}

//
// Initialize encryption key
//
bool NetworkServerManager::_initEncryptionKey(const QString &file)
{
    const QByteArray *keyData = NULL;

    if (_encryptionKey)
        return (true);
    if (!(keyData = _QFile::readFile(file)))
        return (false);
    if (!(_encryptionKey = new QSslKey(*keyData, QSsl::Rsa, QSsl::Pem, QSsl::PrivateKey, "server")))
    {
        qDebug() << " Error during encryption key interpretation";
        delete keyData;
        return (false);
    }
    delete keyData;
    return (true);
}

//
// Initialize encryption certificate
//
bool NetworkServerManager::_initEncryptionCertificate(const QString &file)
{
    const QByteArray *certificateData = NULL;

    if (_encryptionCertificate)
        return (true);
    if (!(certificateData = _QFile::readFile(file)))
        return (false);
    if (!(_encryptionCertificate = new QSslCertificate(*certificateData)))
    {
        qDebug() << " Error during encryption certificate interpretation";
        delete certificateData;
        return (false);
    }
    delete certificateData;
    return (true);
}

//
// Make server listening on choosen port
//
bool NetworkServerManager::_listen(quint16 portNumber)
{
    _portNumber = portNumber;
    if (!_server.listen(QHostAddress::Any, portNumber))
    {
        qDebug() << " Could not start server";
        return (false);
    }
    qDebug() << " Listening to port" << portNumber << "...";
    return (true);
}

//
// Create and initialize a new client
// Note: The `static quint64 clientId` is a bit ugly, FIX THIS AS SOON AS
// the USER MODULE is achieved
//
void NetworkServerManager::_incomingConnection(qintptr socketDescriptor)
{
    static quint64 clientId = 1;
    NetworkClient *client = new NetworkClient(clientId++, this);

    qDebug() << Q_FUNC_INFO;
    qDebug() << "" << socketDescriptor << "New client connected";
    if (_bindClientSignalsToSlots(client) &&
        client->start(_DEFAULT_PROTOCOL, socketDescriptor,
                      *_encryptionKey, *_encryptionCertificate))
    {
        _clientSockets[socketDescriptor] = client;
        _clientIds[client->getClientId()] = client;
    }
    else
    {
        qDebug() << "" << socketDescriptor << " Error during client initialization";
        delete client;
    }
}

//
// Bind `NetworkClient` signals to `this` slots
//
bool NetworkServerManager::_bindClientSignalsToSlots(NetworkClient *client)
{
    return (connect(client, SIGNAL(readyRead(qintptr)),
                    this, SLOT(_onClientReadyRead(qintptr)), Qt::QueuedConnection) &&
            connect(client, SIGNAL(bytesWritten(qintptr, qint64)),
                    this, SLOT(_onClientBytesWritten(qintptr, qint64)), Qt::QueuedConnection) &&
            connect(client, SIGNAL(disconnected(qintptr)),
                    this, SLOT(_deleteClient(qintptr)), Qt::QueuedConnection) &&
            connect(client, SIGNAL(encryptionErrors(qintptr, QList<QSslError>)),
                    this, SLOT(_onClientEncryptionError(qintptr, QList<QSslError>)), Qt::QueuedConnection));
}

//
// Supposed to fill the client input buffer
//
void NetworkServerManager::_onClientReadyRead(qintptr socketDescriptor)
{
    NetworkClient *client = _clientSockets[socketDescriptor];
    InstructionBuffer *instruction = client->getInputBuffer();
    qint64 bytesAvailable = client->bytesAvailable();

    qDebug() << Q_FUNC_INFO;
    qDebug() << "" << socketDescriptor << "Ready to read" << bytesAvailable << "bytes";
    while (bytesAvailable > 0)
    {
        if (!instruction)
        {
            instruction = new InstructionBuffer();
            instruction->setPeerId(client->getClientId());
            instruction->setLocalTransmitter(this);
            client->setInputBuffer(instruction);
        }
        if (!_read(instruction, *client, bytesAvailable))
        {
            _deleteClient(client);
            return ;
        }
        _finalizeReceivedInstruction(instruction, client->getClientId());
    }
}

//
// Supposed to handle the outcoming data
//
void NetworkServerManager::_onClientBytesWritten(qintptr socketDescriptor, qint64 size)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "" << socketDescriptor << "Written bytes :" << size;
}

//
// Delete a disconnected client
//
void NetworkServerManager::_deleteClient(qintptr socketDescriptor)
{
    NetworkClient *client = _clientSockets[socketDescriptor];

    qDebug() << Q_FUNC_INFO;
    qDebug() << "" << socketDescriptor << "Client disconnected";
    _deleteClient(client);
}

//
// Delete a client
//
void NetworkServerManager::_deleteClient(NetworkClient *client)
{
    _server.disconnect(client, 0, 0, 0);
    _clientSockets.remove(client->getSocketDescriptor());
    _clientIds.remove(client->getClientId());
    delete client;
    qDebug() << "Client deleted";
}

//
// Print client encryption errors
//
void NetworkServerManager::_onClientEncryptionError(qintptr socketDescriptor, QList<QSslError> errors)
{
    QString errorStr = " ";

    qDebug() << Q_FUNC_INFO;
    qDebug() << "" << socketDescriptor << "Encryption error";
    for (auto e : errors)
        errorStr.append(e.errorString()).append("\n");
    qDebug() << errorStr;
}

//
// Slot activated in the case of a non threaded functionality
// This functionality runs on the main thread in the Qt event loop
// Handle what to do when a new instruction (from the instruction
// bus) is received
//
void NetworkServerManager::onInstructionPushed()
{
    InstructionBuffer *instruction = static_cast<InstructionBuffer *>(_popInstruction());
    NetworkClient *client = NULL;

    qDebug() << Q_FUNC_INFO;
    if (!_instructionPushedIsValid(instruction))
    {
        delete instruction;
        return ;
    }
    if (instruction->getPeerId() == 0 ||
        !_clientIds.contains(instruction->getPeerId()))
    {
        qDebug() << "Error: Invalid network peer id";
        delete instruction;
        return ;
    }
    client = _clientIds[instruction->getPeerId()];
    if (!_write(instruction, *client))
        _deleteClient(client);
    delete instruction;
}
