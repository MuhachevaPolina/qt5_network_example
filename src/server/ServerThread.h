#pragma once

// #include <QThread>
#include <QTcpSocket>
#include <QRunnable>

class ServerTask: public QRunnable
{
public:
  void run() override;
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