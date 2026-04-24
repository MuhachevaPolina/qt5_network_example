#include <QString>
#include <QTcpServer>
#include <QDataStream>
#include <QTcpSocket>

namespace utilities
{
  class SimpleServer : public QTcpServer
  {
  public:
    qintptr getDescriptor();

  protected:
    void incomingConnection(qintptr socketDescriptor) override;

  private:
    qintptr m_descriptor = -1;
  };

  QString readOneFortuneAsClient(QTcpSocket &socket);
}