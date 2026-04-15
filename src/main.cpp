#include <QApplication>
#include <QtCore>

#include <stdlib.h>

#include "server/Dialog.h"
#include "client/BlockingClient.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    dialog.show();
    // return app.exec();

    BlockingClient client;
    client.show();
    // return app.exec();

    return app.exec();
}