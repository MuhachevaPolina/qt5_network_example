#pragma once

#include <QObject>
#include <QString>
#include <QWaitCondition>

class ClientWorker: public QObject
{
  Q_OBJECT

public:
  ClientWorker(const QString& hostName, uint port, QObject *parent = nullptr);
signals:
  void finished();
  void newFortune(const QString& fortune);
  void error(int socketError, const QString& message);
public slots:
  void process();
private:
  QString m_hostName;
  uint m_port;
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