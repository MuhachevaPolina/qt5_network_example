#include <QApplication>
#include <QtCore>

#include <stdlib.h>

#include "server/Dialog.h"
#include "client/BlockingClient.h"

int main(int argc, char *argv[])
{
    QApplication appServer(argc, argv);
    Dialog dialog;
    dialog.show();
    // return app.exec();

    QApplication appClient(argc, argv);
    BlockingClient client;
    client.show();
    // return app.exec();

    return appServer.exec();
}