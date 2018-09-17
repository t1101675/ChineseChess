#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = 0);
    ~ClientDialog();
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLineEdit *ipEdit;
    QLineEdit *portEdit;

signals:
    void okClicked(QString IP, int port);
    void quitClicked();
    void newConnection();

private slots:
    void on_okButton_clicked();

    void on_quitButton_clicked();

    void on_cancelButton_clicked();

public slots:
    void newConnect();

private:
    Ui::ClientDialog *ui;
    bool isConnect;
};

#endif // CLIENTDIALOG_H
