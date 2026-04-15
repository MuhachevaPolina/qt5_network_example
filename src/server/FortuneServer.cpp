#include "FortuneServer.h"

#include "ServerThread.h"

#include <QRandomGenerator>
#include <QDataStream>
#include <QByteArray>

#include <stdlib.h>

FortuneServer::FortuneServer(QObject *parent)
    : QTcpServer(parent)
{
  fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
    << tr("You've got to think about tomorrow.")
    << tr("You will be surprised by a loud noise.")
    << tr("You will feel hungry again in another hour.")
    << tr("You might have mail.")
    << tr("You cannot kill time without injuring eternity.")
    << tr("Computers are not intelligent. They only think they are.");
}

void FortuneServer::incomingConnection(qintptr socketDescriptor)
{
  QString fortune = fortunes.at(QRandomGenerator::global()->bounded(fortunes.size()));
  // ServerThread *thread = new ServerThread(socketDescriptor, fortune, this);
  connect(thread, &ServerThread::finished, thread, &ServerThread::deleteLater);
  thread->start();
}