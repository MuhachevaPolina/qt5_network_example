#ifndef DIALOG_H
#define DIALOG_H

#include "FortuneServer.h"

#include <QWidget>
#include <QThreadPool>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class Dialog : public QWidget
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    FortuneServer server;
    QThreadPool m_threadPool;
};

#endif