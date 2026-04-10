#pragma once

#include <QTcpServer>
#include <QStringList>

class FortuneServer : public QTcpServer
{
  Q_OBJECT

public:
  FortuneServer(QObject *parent = nullptr);

protected:
  void incomingConnection(qintptr socketDescriptor) override;

private:
  QStringList fortunes;
};