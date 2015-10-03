#ifndef     NETWORKSERVER_HPP
# define    NETWORKSERVER_HPP

# include <QTcpServer>
# include <QSslKey>
# include <QSslCertificate>
# include <QList>

class NetworkClient;

class NetworkServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit NetworkServer(QObject *parent = 0);
    ~NetworkServer();

private:
    static const QString _ENCRYPTION_KEY_FILE;
    static const QString _ENCRYPTION_CERTIFICATE_FILE;

    quint16 _portNumber;
    QSslKey *_encryptionKey = NULL;
    QSslCertificate *_encryptionCertificate = NULL;
    QList<NetworkClient *> _clientSockets;

public:
    bool start(quint16 portNumber);

private:
    bool _initEncryptionKey(const QString &file);
    bool _initEncryptionCertificate(const QString &file);
    bool _listen(quint16 portNumber);

protected:
    void incomingConnection(qintptr socketDescriptor);

signals:

public slots:
};

#endif      // NETWORKSERVER_HPP