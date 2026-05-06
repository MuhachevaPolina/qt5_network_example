#include <src/client/ClientWorker.h>
#include <src/server/FortuneServer.h>

#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QEventLoop>

TEST(ClientWorkerTests, CheckForOneFortuneCorrect)
{
  int argc = 0;
  char *argv[] = {nullptr};
  QCoreApplication app(argc, argv);

  FortuneServer server;
  ASSERT_TRUE(server.listen(QHostAddress::LocalHost, 0));

  ClientWorker *worker = new ClientWorker(server.serverAddress().toString(), server.serverPort());
  QThread *workerThread = new QThread;
  worker->moveToThread(workerThread);

  QObject::connect(workerThread, &QThread::started, worker, &ClientWorker::process);

  // connect(worker, &ClientWorker::newFortune, this, &BlockingClient::showFortune);
  // connect(worker, &ClientWorker::error, this, &BlockingClient::displayError);

  QObject::connect(worker, &ClientWorker::finished, workerThread, &QThread::quit);
  QObject::connect(worker, &ClientWorker::finished, worker, &ClientWorker::deleteLater);
  QObject::connect(workerThread, &QThread::finished, workerThread, &QThread::deleteLater);

  bool isFortuneGotten = false;
  bool isWorkerFinished = false;
  bool isError = false;

  QString gottenFortune;
  QObject::connect(worker, &ClientWorker::newFortune, 
    [&](const QString& fortune) 
    {
      gottenFortune = fortune;
      isFortuneGotten = true;
    }
  );

  QObject::connect(worker, &ClientWorker::finished, 
    [&]() 
    {
      isWorkerFinished = true;
    }
  );

  QObject::connect(worker, &ClientWorker::error, 
    [&]() 
    {
      isError = true;
    }
  );

  workerThread->start();

  QEventLoop loop;
  QObject::connect(worker, &ClientWorker::finished, &loop, &QEventLoop::quit);
  
  loop.exec();

  workerThread->quit();
  workerThread->wait();

  EXPECT_TRUE(isFortuneGotten);
  EXPECT_TRUE(isWorkerFinished);
  EXPECT_FALSE(isError);
  EXPECT_FALSE(gottenFortune.isEmpty());
}

/*
TEST(ClientWorkerTests, CheckForErrorSignal)
{
}
*/