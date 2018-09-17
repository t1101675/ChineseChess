#include "netdialog.h"
#include "ui_netdialog.h"

NetDialog::NetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetDialog)
{
    ui->setupUi(this);
}

NetDialog::~NetDialog()
{
    delete ui;
}
