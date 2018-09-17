#include "clientdialog.h"
#include "ui_clientdialog.h"
#include <QRegExpValidator>

ClientDialog::ClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    okButton = ui->okButton;
    cancelButton = ui->cancelButton;
    ipEdit = ui->ipEdit;
    portEdit = ui->portEdit;

    QRegExp regExp("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
    ipEdit->setValidator(new QRegExpValidator(regExp, this));

    QRegExp portExp("^([0-9]|[1-9]\\d|[1-9]\\d{2}|[1-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5])$");
    portEdit->setValidator(new QRegExpValidator(portExp, this));

    isConnect = false;
}

ClientDialog::~ClientDialog()
{
    delete ui;
}

void ClientDialog::on_okButton_clicked()
{
    ui->statusLabel->setText(tr("连接中..."));
    emit okClicked(ipEdit->text(), portEdit->text().toInt());
    okButton->setEnabled(false);
    ui->quitButton->setEnabled(true);
}

void ClientDialog::on_quitButton_clicked()
{
    isConnect = false;
    ui->statusLabel->setText(tr("输入IP和端口号以建立连接"));
    emit quitClicked();
    ui->quitButton->setEnabled(false);
    ui->okButton->setEnabled(true);
}

void ClientDialog::on_cancelButton_clicked()
{
    if (isConnect) emit newConnection();
    reject();
}

void ClientDialog::newConnect() {
    ui->statusLabel->setText(tr("已连接"));
    isConnect = true;
    okButton->setEnabled(false);
    ui->quitButton->setEnabled(true);
}
