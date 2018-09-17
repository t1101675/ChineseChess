/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSet_server;
    QAction *actionConnect_to_server;
    QAction *actionLoad_file;
    QAction *actionSave_file;
    QAction *action;
    QAction *action_Qt;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuConnect;
    QMenu *menuFile;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionSet_server = new QAction(MainWindow);
        actionSet_server->setObjectName(QStringLiteral("actionSet_server"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/server.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSet_server->setIcon(icon);
        actionConnect_to_server = new QAction(MainWindow);
        actionConnect_to_server->setObjectName(QStringLiteral("actionConnect_to_server"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/client.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_to_server->setIcon(icon1);
        actionLoad_file = new QAction(MainWindow);
        actionLoad_file->setObjectName(QStringLiteral("actionLoad_file"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/end.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_file->setIcon(icon2);
        actionSave_file = new QAction(MainWindow);
        actionSave_file->setObjectName(QStringLiteral("actionSave_file"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_Qt = new QAction(MainWindow);
        action_Qt->setObjectName(QStringLiteral("action_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 32));
        menuConnect = new QMenu(menuBar);
        menuConnect->setObjectName(QStringLiteral("menuConnect"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuConnect->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuConnect->addAction(actionSet_server);
        menuConnect->addAction(actionConnect_to_server);
        menuFile->addAction(actionLoad_file);
        menuFile->addAction(actionSave_file);
        menu->addAction(action);
        menu->addAction(action_Qt);
        mainToolBar->addAction(actionSet_server);
        mainToolBar->addAction(actionConnect_to_server);
        mainToolBar->addAction(actionLoad_file);
        mainToolBar->addAction(actionSave_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSet_server->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\234\215\345\212\241\345\231\250", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSet_server->setShortcut(QApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionConnect_to_server->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\345\210\260\346\234\215\345\212\241\345\231\250", nullptr));
#ifndef QT_NO_SHORTCUT
        actionConnect_to_server->setShortcut(QApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad_file->setText(QApplication::translate("MainWindow", "\350\275\275\345\205\245\346\256\213\345\261\200", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_file->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\243\213\345\261\200", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\344\270\255\345\233\275\350\261\241\346\243\213", nullptr));
        action_Qt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", nullptr));
        menuConnect->setTitle(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "\350\275\275\345\205\245", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
