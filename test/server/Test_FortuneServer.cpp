#include <test/server/utilities.h>
#include <src/server/FortuneServer.h>

#include <gtest/gtest.h>
#include <QCoreApplication>

TEST(FortuneServerTests, CheckForOneFortune)
{
  int argc = 0;
  char *argv[] = {nullptr};
  QCoreApplication app(argc, argv);

  FortuneServer server;
  ASSERT_TRUE(server.listen(QHostAddress::LocalHost, 0));

  QTcpSocket clientSocket;
  clientSocket.connectToHost(QHostAddress::LocalHost, server.serverPort());

  ASSERT_TRUE(clientSocket.waitForConnected(3000));
  QCoreApplication::processEvents();

  const QString gottenFortune = utilities::readOneFortuneAsClient(clientSocket);
  ASSERT_FALSE(gottenFortune.isEmpty());
}