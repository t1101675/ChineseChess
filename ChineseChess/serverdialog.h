#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QRegExp>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QHostInfo>

namespace Ui {
class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = 0);
    ~ServerDialog();

    QPushButton *okButton;
    QPushButton *cancelButton;
    QLineEdit *ipEdit;
    QLineEdit *portEdit;

signals:
    void okClicked(QString IP, int port);
    void quitClicked();
    void newConnection();

private slots:
    void on_quitButton_clicked();

    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_ipEdit_textChanged(const QString &arg1);

public slots:
    void newConnect();

private:
    void setSelfIP();

    Ui::ServerDialog *ui;
    bool isConnect;
};

#endif // SERVERDIALOG_H
