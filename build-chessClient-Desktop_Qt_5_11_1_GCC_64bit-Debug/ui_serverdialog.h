/********************************************************************************
** Form generated from reading UI file 'serverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERDIALOG_H
#define UI_SERVERDIALOG_H

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

class Ui_ServerDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *portEdit;
    QLineEdit *ipEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *okButton;
    QPushButton *quitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ServerDialog)
    {
        if (ServerDialog->objectName().isEmpty())
            ServerDialog->setObjectName(QStringLiteral("ServerDialog"));
        ServerDialog->resize(285, 174);
        layoutWidget = new QWidget(ServerDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 258, 145));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        portEdit = new QLineEdit(layoutWidget);
        portEdit->setObjectName(QStringLiteral("portEdit"));

        gridLayout->addWidget(portEdit, 1, 1, 1, 1);

        ipEdit = new QLineEdit(layoutWidget);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));

        gridLayout->addWidget(ipEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        horizontalLayout->addWidget(statusLabel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_2->addWidget(okButton);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout_2->addWidget(quitButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(ServerDialog);

        QMetaObject::connectSlotsByName(ServerDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerDialog)
    {
        ServerDialog->setWindowTitle(QApplication::translate("ServerDialog", "\350\256\276\347\275\256\346\234\215\345\212\241\345\231\250", nullptr));
        label->setText(QApplication::translate("ServerDialog", "IP:", nullptr));
        label_2->setText(QApplication::translate("ServerDialog", "Port:", nullptr));
        portEdit->setText(QApplication::translate("ServerDialog", "8888", nullptr));
        ipEdit->setText(QString());
        statusLabel->setText(QApplication::translate("ServerDialog", "\350\276\223\345\205\245\347\253\257\345\217\243\345\217\267\344\273\245\350\256\276\347\275\256\346\234\215\345\212\241\345\231\250", nullptr));
        okButton->setText(QApplication::translate("ServerDialog", "OK", nullptr));
        quitButton->setText(QApplication::translate("ServerDialog", "Quit", nullptr));
        cancelButton->setText(QApplication::translate("ServerDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerDialog: public Ui_ServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERDIALOG_H
