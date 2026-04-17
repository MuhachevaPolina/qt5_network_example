#pragma once

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class ClientWorker: public QObject
{
  Q_OBJECT

public:

private:

};

/*
//! [0]
class ClientThread : public QThread
{
    Q_OBJECT

public:
    ClientThread(QObject *parent = nullptr);
    ~ClientThread();

    void requestNewFortune(const QString &hostName, quint16 port);
    void run() override;

signals:
    void newFortune(const QString &fortune);
    void error(int socketError, const QString &message);

private:
    QString hostName;
    quint16 port;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;
};
//! [0]
*/