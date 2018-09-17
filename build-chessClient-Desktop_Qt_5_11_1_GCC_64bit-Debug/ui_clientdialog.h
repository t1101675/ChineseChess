/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *ipEdit;
    QLabel *label_2;
    QLineEdit *portEdit;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *quitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ClientDialog)
    {
        if (ClientDialog->objectName().isEmpty())
            ClientDialog->setObjectName(QStringLiteral("ClientDialog"));
        ClientDialog->resize(279, 164);
        widget = new QWidget(ClientDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 258, 139));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ipEdit = new QLineEdit(widget);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));

        gridLayout->addWidget(ipEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        portEdit = new QLineEdit(widget);
        portEdit->setObjectName(QStringLiteral("portEdit"));

        gridLayout->addWidget(portEdit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        statusLabel = new QLabel(widget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        verticalLayout->addWidget(statusLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(widget);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout->addWidget(quitButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ClientDialog);

        QMetaObject::connectSlotsByName(ClientDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientDialog)
    {
        ClientDialog->setWindowTitle(QApplication::translate("ClientDialog", "\345\273\272\347\253\213\350\277\236\346\216\245", nullptr));
        label->setText(QApplication::translate("ClientDialog", "IP:", nullptr));
        ipEdit->setText(QApplication::translate("ClientDialog", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("ClientDialog", "Port:", nullptr));
        portEdit->setText(QApplication::translate("ClientDialog", "8888", nullptr));
        statusLabel->setText(QApplication::translate("ClientDialog", "\350\276\223\345\205\245IP\345\222\214\347\253\257\345\217\243\345\217\267\344\273\245\345\273\272\347\253\213\350\277\236\346\216\245", nullptr));
        okButton->setText(QApplication::translate("ClientDialog", "OK", nullptr));
        quitButton->setText(QApplication::translate("ClientDialog", "Quit", nullptr));
        cancelButton->setText(QApplication::translate("ClientDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientDialog: public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
