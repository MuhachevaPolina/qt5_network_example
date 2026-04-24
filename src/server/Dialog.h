#ifndef DIALOG_H
#define DIALOG_H

#include <src/server/FortuneServer.h>

#include <QWidget>

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
  QLabel *m_statusLabel;
  QPushButton *m_quitButton;
  FortuneServer m_server;
};

#endif