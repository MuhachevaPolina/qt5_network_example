#include <src/server/ServerTask.h>

#include <test/server/utilities.h>

#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QElapsedTimer>

TEST(SeverTask, CheckForOneFortune)
{
  utilities::SimpleServer server;
  ASSERT_TRUE(server.listen(QHostAddress::LocalHost, 0));

  QTcpSocket clientSocket;
  clientSocket.connectToHost(QHostAddress::LocalHost, server.serverPort());
  ASSERT_TRUE(clientSocket.waitForConnected(3000));
  
  ASSERT_TRUE(server.waitForNewConnection(3000));

  qintptr err = -1;
  qintptr descriptor = server.getDescriptor();
  ASSERT_NE(descriptor, err);

  const QString fortune = "it's predicted that you ran a test for a ServerTask!";

  ServerTask task(descriptor, fortune);
  task.run();
  const QString gottenFortune = utilities::readOneFortuneAsClient(clientSocket);
  EXPECT_EQ(fortune, gottenFortune);
}