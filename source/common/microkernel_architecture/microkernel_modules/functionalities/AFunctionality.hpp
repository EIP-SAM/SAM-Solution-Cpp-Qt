#ifndef AFUNCTIONALITY_HPP_
# define AFUNCTIONALITY_HPP_

# include "AInstructionBusClient.hpp"
# include <QThread>

//
// Note: Overload the run() method in child classes
// Then implement what the functionality is supposed to do
//

class AFunctionality : public AInstructionBusClient
{
    Q_OBJECT

public:
    enum eType
    {
        INVALID = 0,
        MICROKERNEL,
        INTERNAL,
        EXTERNAL
    };

private:
    QThread *_thread;
    bool _running;
    bool _threaded;

protected:
    AFunctionality(eClientId clientId, bool threaded = true);

public:
    virtual ~AFunctionality();

    bool start();
    void stop();

    bool isRunning() const;

protected slots:
    virtual void _run() = 0;

private slots:
    void _fctStarted();
    void _fctFinished();

signals:
    void started();
    void stopped();
};

#endif // !AFUNCTIONALITY_HPP_
