#pragma once

#include <QTcpServer>
#include <QStringList>
#include <QThreadPool>

class FortuneServer : public QTcpServer
{
  Q_OBJECT

public:
  FortuneServer(QObject *parent = nullptr);

protected:
  void incomingConnection(qintptr socketDescriptor) override;

private:
  QStringList m_fortunes;
  QThreadPool m_pool;
};