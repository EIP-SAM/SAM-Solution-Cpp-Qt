#ifndef ANETWORK_INSTRUCTION_HPP_
# define ANETWORK_INSTRUCTION_HPP_

# include "AInstruction.hpp"

//
// Contain the specific methods to handle an
// instruction as a I/O network buffer
//

class ANetworkInstruction : public AInstruction
{
private:
    int _dataValidUntilPos = 0;
    quint64 _peerId = 0;

public:
    ANetworkInstruction();
    ANetworkInstruction(const ANetworkInstruction &);
    ANetworkInstruction(const QByteArray &);
    virtual ~ANetworkInstruction();

    void append(const QByteArray &);
    void append(const QByteArray &, int);
    void setPeerId(quint64 peerId);

    int getNextReadSize() const;
    quint64 getPeerId() const;

private:
    void _append(const QByteArray &, int);
};

#endif // !ANETWORK_INSTRUCTION_HPP_
