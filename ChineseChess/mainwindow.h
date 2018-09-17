#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QLCDNumber>
#include <QPushButton>
#include <QTimerEvent>
#include <QMediaPlayer>

#include "network.h"
#include "coder.h"
#include "chessboard.h"
#include "clientdialog.h"
#include "serverdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void timerEvent(QTimerEvent* event);

    static const int timeLimit;

    Chessboard *chessboard;
    Network *network;
    Coder *coder;
    QLCDNumber *lcd;
    QPushButton *startButton;
    QPushButton *newGameButton;
    QPushButton *endgameButton;
    QPushButton *admitButton;
    QPushButton *quitButton;

    ServerDialog *serverDialog;
    ClientDialog *clientDialog;

    QMediaPlayer *player;

public slots:
    void serverConnect();
    void clientConnect();
    void clickStart();
    void clickEndGame();
    void clickNewGame();
    void clickQuitButton();
    void newReadMessage(QString str);
    void oneMove();
    void oppoOneMove();
    void win();
    void lose();
    void timeOut();
    void admit();
    void checking();
    void disconnect();

private slots:
    void on_actionSet_server_triggered();
    void on_actionConnect_to_server_triggered();
    void on_actionLoad_file_triggered();

    void on_actionSave_file_triggered();

    void on_action_triggered();

    void on_action_Qt_triggered();

private:
    void initial();
    void initialConnect();
    void loadFile(const QString &fileName);
    void saveFile(const QString &fileName);
    void start();
    void myTurn();
    void resetTime();
    void readyStart();
    void gameEnd();

    bool timming;
    bool oppoStart;
    bool meStart;
    bool fileLoaded;
    bool gameCreated;
    Side first;
    int timeValue;
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
