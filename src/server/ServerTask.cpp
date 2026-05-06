#include <src/server/ServerTask.h>

#include <QDataStream>
#include <QByteArray>

ServerTask::ServerTask(qintptr socketDescriptor, const QString& fortune)
: m_socketDescriptor(socketDescriptor), m_fortune(fortune)
{}

void ServerTask::run()
{
  QTcpSocket tcpSocket;

  if (!tcpSocket.setSocketDescriptor(this->m_socketDescriptor)) 
  {
    emit error(tcpSocket.error());
    return;
  }

  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_0);
  out << this->m_fortune;

  tcpSocket.write(block);

  tcpSocket.disconnectFromHost();
  tcpSocket.waitForDisconnected();
}

/*
ServerThread::ServerThread(int socketDescriptor, const QString &fortune, QObject *parent)
  : QThread(parent), socketDescriptor(socketDescriptor), text(fortune)
{}

void ServerThread::run()
{
  QTcpSocket tcpSocket;

  if (!tcpSocket.setSocketDescriptor(socketDescriptor)) 
  {
    emit error(tcpSocket.error());
    return;
  }

  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_0);
  out << text;
  tcpSocket.write(block);
  tcpSocket.disconnectFromHost();
  tcpSocket.waitForDisconnected();
}
*/
