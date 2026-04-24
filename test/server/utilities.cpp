#include <test/server/utilities.h>

qintptr utilities::SimpleServer::getDescriptor()
{
  return this->m_descriptor;
}

void utilities::SimpleServer::incomingConnection(qintptr socketDescriptor)
{
  this->m_descriptor = socketDescriptor;
}

QString utilities::readOneFortuneAsClient(QTcpSocket &socket)
{
  const int Timeout = 5 * 1000;

  QDataStream in(&socket);
  in.setVersion(QDataStream::Qt_4_0);
  QString fortune;
  //! [11] //! [12]

  do
  {
    if (!socket.waitForReadyRead(Timeout))
    {
      // emit error(socket.error(), socket.errorString());
      // emit finished();
      return "";
    }

    in.startTransaction();
    in >> fortune;
  } while (!in.commitTransaction());
  //! [12] //! [15]

  return fortune;

  // mutex.lock();
  // emit newFortune(fortune);
  // emit finished();
}