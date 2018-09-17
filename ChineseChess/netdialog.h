#ifndef NETDIALOG_H
#define NETDIALOG_H

#include <QDialog>

namespace Ui {
class NetDialog;
}

class NetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetDialog(QWidget *parent = 0);
    ~NetDialog();

private:
    Ui::NetDialog *ui;
};

#endif // NETDIALOG_H
