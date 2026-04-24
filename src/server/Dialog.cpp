#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include <src/server/Dialog.h>
#include <src/server/FortuneServer.h>

Dialog::Dialog(QWidget *parent)
    : QWidget(parent)
{
    this->m_statusLabel = new QLabel;
    this->m_statusLabel->setWordWrap(true);
    this->m_quitButton = new QPushButton(tr("Quit"));
    this->m_quitButton->setAutoDefault(false);

    if (!this->m_server.listen()) {
        QMessageBox::critical(this, tr("Threaded Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(this->m_server.errorString()));
        close();
        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    this->m_statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Fortune Client example now.")
                         .arg(ipAddress).arg(this->m_server.serverPort()));

    connect(this->m_quitButton, &QPushButton::clicked, this, &Dialog::close);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(this->m_quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(this->m_statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
    setWindowTitle(tr("Threaded Fortune Server"));
}