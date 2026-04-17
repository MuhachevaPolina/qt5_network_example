#pragma once

// #include <QThread>
#include <QTcpSocket>
#include <QRunnable>
#include <QString>

class ServerTask:  public QObject, public QRunnable
{
  Q_OBJECT

public:
  ServerTask(qintptr socketDescriptor, const QString& fortune);
  void run() override;
signals:
  void error(QTcpSocket::SocketError socketError);
private:
  QString m_fortune;
  qintptr m_socketDescriptor;
};

/*
class ServerThread : public QThread
{
  Q_OBJECT

public:
  ServerThread(int socketDescriptor, const QString &fortune, QObject *parent);

  void run() override;

signals:
  void error(QTcpSocket::SocketError socketError);

private:
  int socketDescriptor;
  QString text;
};
*/