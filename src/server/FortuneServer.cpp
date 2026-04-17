#include "FortuneServer.h"

#include "ServerTask.h"

#include <QRandomGenerator>
#include <QDataStream>
#include <QByteArray>

#include <stdlib.h>

FortuneServer::FortuneServer(QObject *parent)
    : QTcpServer(parent)
{
  m_fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
    << tr("You've got to think about tomorrow.")
    << tr("You will be surprised by a loud noise.")
    << tr("You will feel hungry again in another hour.")
    << tr("You might have mail.")
    << tr("You cannot kill time without injuring eternity.")
    << tr("Computers are not intelligent. They only think they are.");
}

void FortuneServer::incomingConnection(qintptr socketDescriptor)
{
  QString fortune = this->m_fortunes.at(QRandomGenerator::global()->bounded(this->m_fortunes.size()));
  // ServerThread *thread = new ServerThread(socketDescriptor, fortune, this);
  this->m_pool.start(new ServerTask(socketDescriptor, fortune));
}