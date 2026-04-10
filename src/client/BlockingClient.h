#pragma once

#include "ClientThread.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QAction;
QT_END_NAMESPACE

//! [0]
class BlockingClient : public QWidget
{
  Q_OBJECT

public:
  BlockingClient(QWidget *parent = nullptr);

private slots:
  void requestNewFortune();
  void showFortune(const QString &fortune);
  void displayError(int socketError, const QString &message);
  void enableGetFortuneButton();

private:
  QLabel *hostLabel;
  QLabel *portLabel;
  QLineEdit *hostLineEdit;
  QLineEdit *portLineEdit;
  QLabel *statusLabel;
  QPushButton *getFortuneButton;
  QPushButton *quitButton;
  QDialogButtonBox *buttonBox;

  ClientThread thread;
  QString currentFortune;
};
//! [0]