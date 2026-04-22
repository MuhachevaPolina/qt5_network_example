#include "ClientWorker.h"

#include <QtNetwork>

ClientWorker::ClientWorker(const QString &hostName, uint port, QObject *parent)
    : QObject(parent), m_hostName(hostName), m_port(port)
{
}

void ClientWorker::process()
{
  const int Timeout = 5 * 1000;

  QTcpSocket socket;
  socket.connectToHost(this->m_hostName, this->m_port);
  //! [6] //! [8]

  if (!socket.waitForConnected(Timeout))
  {
    emit error(socket.error(), socket.errorString());
    emit finished();
    return;
  }
  //! [8] //! [11]

  QDataStream in(&socket);
  in.setVersion(QDataStream::Qt_4_0);
  QString fortune;
  //! [11] //! [12]

  do
  {
    if (!socket.waitForReadyRead(Timeout))
    {
      emit error(socket.error(), socket.errorString());
      emit finished();
      return;
    }

    in.startTransaction();
    in >> fortune;
  } while (!in.commitTransaction());
  //! [12] //! [15]

  // mutex.lock();
  emit newFortune(fortune);
  emit finished();
  //! [7]

  // cond.wait(&mutex);
  // serverName = hostName;
  // serverPort = port;
  // mutex.unlock();
}

/*
ClientThread::ClientThread(QObject *parent)
    : QThread(parent), quit(false)
{
}

//! [0]
ClientThread::~ClientThread()
{
    mutex.lock();
    quit = true;
    cond.wakeOne();
    mutex.unlock();
    wait();
}
//! [0]

//! [1] //! [2]
void ClientThread::requestNewFortune(const QString &hostName, quint16 port)
{
//! [1]
    QMutexLocker locker(&mutex);
    this->hostName = hostName;
    this->port = port;
//! [3]
    if (!isRunning())
        start();
    else
        cond.wakeOne();
}
//! [2] //! [3]

//! [4]
void ClientThread::run()
{
    mutex.lock();
//! [4] //! [5]
    QString serverName = hostName;
    quint16 serverPort = port;
    mutex.unlock();
//! [5]

//! [6]
    while (!quit) {
//! [7]
        const int Timeout = 5 * 1000;

        QTcpSocket socket;
        socket.connectToHost(serverName, serverPort);
//! [6] //! [8]

        if (!socket.waitForConnected(Timeout)) {
            emit error(socket.error(), socket.errorString());
            return;
        }
//! [8] //! [11]

        QDataStream in(&socket);
        in.setVersion(QDataStream::Qt_4_0);
        QString fortune;
//! [11] //! [12]

        do {
            if (!socket.waitForReadyRead(Timeout)) {
                emit error(socket.error(), socket.errorString());
                return;
            }

            in.startTransaction();
            in >> fortune;
        } while (!in.commitTransaction());
//! [12] //! [15]

        mutex.lock();
        emit newFortune(fortune);
//! [7]

        cond.wait(&mutex);
        serverName = hostName;
        serverPort = port;
        mutex.unlock();
    }
//! [15]
}
*/
