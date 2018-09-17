#include "serverdialog.h"
#include "ui_serverdialog.h"
#include <iostream>
#include <QRegExp>
#include <QRegExpValidator>

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
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
    setSelfIP();
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

void ServerDialog::on_quitButton_clicked()
{
    isConnect = false;
    ui->statusLabel->setText(tr("输入端口号以设置服务器"));
    emit quitClicked();
    ui->okButton->setEnabled(true);
    ui->quitButton->setEnabled(false);
}

void ServerDialog::on_okButton_clicked()
{
    ui->statusLabel->setText(tr("等待连接中..."));
    emit okClicked(ipEdit->text(), portEdit->text().toInt());
    ui->okButton->setEnabled(false);
    ui->quitButton->setEnabled(true);
}

void ServerDialog::newConnect() {
    ui->statusLabel->setText(tr("已连接"));
    isConnect = true;
    okButton->setEnabled(false);
}


void ServerDialog::on_cancelButton_clicked()
{
    if (isConnect) emit newConnection();
    reject();
}

void ServerDialog::setSelfIP() {
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol) {
            ui->ipEdit->setText(address.toString());
            break;
        }
        else if (address.isNull()) {
            std::cout << "No" << std::endl;
            continue;

        }
    }
}

void ServerDialog::on_ipEdit_textChanged(const QString &arg1)
{

}
