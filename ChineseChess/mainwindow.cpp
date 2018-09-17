#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chessman.h"
#include "serverdialog.h"
#include "clientdialog.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
#include <QByteArray>
#include <QLayout>
#include <QTimer>
#include <QMessageBox>
#include <fstream>
#include <QStyle>

const int MainWindow::timeLimit = 20;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(600, 0);
    lcd = new QLCDNumber;
    lcd->setMinimumSize(200, 120);
    chessboard = new Chessboard(this);

    setWindowTitle("中国象棋");

    QFont font("System", 20);
    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_FileIcon);
    ui->actionSave_file->setIcon(icon);

    startButton = new QPushButton;
    startButton->setFont(font);
    startButton->setText(tr("开始"));
    startButton->setMinimumSize(200, 100);
    startButton->setEnabled(false);

    admitButton = new QPushButton;
    admitButton->setFont(font);
    admitButton->setText(tr("认输"));
    admitButton->setMinimumSize(200, 100);
    admitButton->setEnabled(false);

    newGameButton = new QPushButton;
    newGameButton->setFont(font);
    newGameButton->setText(tr("新的棋局"));
    newGameButton->setMinimumSize(200, 100);

    endgameButton = new QPushButton;
    endgameButton->setFont(font);
    endgameButton->setText(tr("残局对战"));
    endgameButton->setMinimumSize(200, 100);

    quitButton = new QPushButton;
    quitButton->setFont(font);
    quitButton->setText(tr("离开"));
    quitButton->setMinimumSize(200, 100);

    player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc://sound/sound/check.mp3"));

    QWidget *center = new QWidget(this);

    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    vLayout->addWidget(lcd);
    vLayout->addWidget(startButton);
    vLayout->addStretch();
    vLayout->addWidget(newGameButton);
    vLayout->addStretch();
    vLayout->addWidget(endgameButton);
    vLayout->addStretch();
    vLayout->addWidget(admitButton);
    vLayout->addStretch();
    vLayout->addWidget(quitButton);
    vLayout->addStretch();
    hLayout->addWidget(chessboard);
    hLayout->addLayout(vLayout);

    center->setLayout(hLayout);
    setCentralWidget(center);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setFixedSize(sizeHint());
    network = new Network(this);
    coder = new Coder(this);

    serverDialog = new ServerDialog(this);
    clientDialog = new ClientDialog(this);

    initialConnect();

    startTimer(1000);
    initial();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event) {
    if (timming) {
        timeValue--;
        lcd->display(timeValue);
        if (timeValue <= 0) timeOut();
    }
}

void MainWindow::initial() {
    timming = false;
    resetTime();
    oppoStart = false;
    meStart = false;
    first = Red;
    fileLoaded = false;
    gameCreated = false;
}

void MainWindow::initialConnect() {
    connect(chessboard, SIGNAL(newSend(ChessInfo*)), coder, SLOT(newSloInfo(ChessInfo*)));
    connect(coder, SIGNAL(newSigInfo(ChessInfo*)), chessboard, SLOT(newRead(ChessInfo*)));
    connect(coder, SIGNAL(newSigInfo(ChessInfo*)), this, SLOT(oppoOneMove()));
    connect(network, SIGNAL(newRead(QByteArray)), coder, SLOT(newSloByte(QByteArray)));
    connect(coder, SIGNAL(newSigMessage(QString)), this, SLOT(newReadMessage(QString)));
    connect(coder, SIGNAL(newSigByte(QByteArray)), network, SLOT(newSend(QByteArray)));

    connect(serverDialog, SIGNAL(okClicked(QString, int)), network, SLOT(startServer(QString,int)));
    connect(clientDialog, SIGNAL(okClicked(QString, int)), network, SLOT(startClient(QString,int)));
    connect(serverDialog, SIGNAL(quitClicked()), network, SLOT(endServer()));
    connect(clientDialog, SIGNAL(quitClicked()), network, SLOT(endClient()));
    connect(network, SIGNAL(serverConnect()), serverDialog, SLOT(newConnect()));
    connect(network, SIGNAL(clientConnect()), clientDialog, SLOT(newConnect()));
    connect(serverDialog, SIGNAL(newConnection()), this, SLOT(serverConnect()));
    connect(clientDialog, SIGNAL(newConnection()), this, SLOT(clientConnect()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(clickQuitButton()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(clickStart()));
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(clickNewGame()));
    connect(endgameButton, SIGNAL(clicked()), this, SLOT(clickEndGame()));
    connect(admitButton, SIGNAL(clicked()), this, SLOT(admit()));

    connect(chessboard, SIGNAL(oneMove()), this, SLOT(oneMove()));
    connect(chessboard, SIGNAL(win()), this, SLOT(win()));
    connect(chessboard, SIGNAL(lose()), this, SLOT(lose()));
    connect(chessboard, SIGNAL(checking()), this, SLOT(checking()));

}

void MainWindow::on_actionSet_server_triggered() {
    serverDialog->show();
}

void MainWindow::on_actionConnect_to_server_triggered() {
    clientDialog->show();
}

void MainWindow::serverConnect() {
    std::cout << "ServerConnect" << std::endl;
    chessboard->setSide(Red);
    coder->setSide(Red);
    chessboard->setTurn(true);
    first = chessboard->getSide();
}

void MainWindow::clientConnect() {
    std::cout << "ClientConnect" << std::endl;
    chessboard->setSide(Black);
    coder->setSide(Black);
    first = chessboard->getSide();
}

void MainWindow::clickStart() {
    if (!network->isConnected()) return;
    coder->newSloMessage("start");
}

void MainWindow::clickEndGame() {
    if (!network->isConnected()) {
        QMessageBox::information(this, "中国象棋", "请先建立连接", QMessageBox::Ok);
        return;
    }
    if (!fileLoaded) {
        QMessageBox::information(this, "中国象棋", "请先导入残局", QMessageBox::Ok);
        return;
    }
    coder->newSloMessage("endgame");
}

void MainWindow::clickNewGame() {
    if (!network->isConnected()) {
        QMessageBox::information(this, "中国象棋", "请先建立连接。", QMessageBox::Ok);
        return;
    }
    chessboard->createChessBoard(chessboard->getSide());
    coder->newSloMessage("newGame");
}

void MainWindow::clickQuitButton() {
    int r = QMessageBox::warning(this, "中国象棋", "您确定要离开吗？", QMessageBox::Yes | QMessageBox::No);
    if (r == QMessageBox::Yes) {
        disconnect();
        close();
    }
}

void MainWindow::newReadMessage(QString str) {
    if (str == "start") {
       int r = QMessageBox::information(this, "中国象棋", "您的对手已经准备好了，您要开始吗？", QMessageBox::Yes | QMessageBox::No);
       if (r == QMessageBox::Yes) {
           start();
           coder->newSloMessage("admitStart");
       }
       else {
           coder->newSloMessage("refuse");
       }
    }
    else if (str == "admitStart") {
        start();
    }
    else if (str == "refuse") {
        QMessageBox::information(this, "中国象棋", "您的对手拒绝了您的请求。", QMessageBox::Ok);
    }
    else if (str == "admit") {
        gameEnd();
        QMessageBox::information(this, "中国象棋", "您的对手认输了！您赢了！！！", QMessageBox::Ok);
    }
    else if (str == "endgame") {
        int r = QMessageBox::information(this, "中国象棋", "您的对手向您发起了残局挑战，您要接受吗？", QMessageBox::Yes | QMessageBox::No);
        if (r == QMessageBox::Yes) {
            coder->newSloMessage("admitRequest");
            readyStart();
        }
        else coder->newSloMessage("refuse");
    }
    else if (str == "admitRequest") {
        chessboard->emitInfo();
        if (first == Red) coder->newSloMessage("red");
        else coder->newSloMessage("black");
        QMessageBox::information(this, "中国象棋", "您的对手接受了您的挑战。点击“开始”，准备对局。", QMessageBox::Ok);
        readyStart();
    }
    else if (str == "red") {
        fileLoaded = true;
        gameCreated = true;
        first = Red;
        startButton->setEnabled(true);
        QMessageBox::information(this, "中国象棋", "红方先走。点击“开始”，准备对局。", QMessageBox::Ok);
    }
    else if (str == "black") {
        fileLoaded = true;
        gameCreated = true;
        first = Black;
        startButton->setEnabled(true);
        QMessageBox::information(this, "中国象棋", "黑方先走。点击“开始”，准备对局。", QMessageBox::Ok);
    }
    else if (str == "newGame") {
        int r = QMessageBox::information(this, "中国象棋", "您的对手向您发起了新局挑战，您要接受吗？", QMessageBox::Yes | QMessageBox::No);
        if (r == QMessageBox::Yes) {
            coder->newSloMessage("admitRequest");
            readyStart();
        }
        else coder->newSloMessage("refuse");
    }
    else if (str == "leave") {
        QMessageBox::information(this, "中国象棋", "您的对手已经离开了游戏。", QMessageBox::Ok);
        gameEnd();
        network->setConnected(false);
    }
    else if (str == "timeOut") {
        QMessageBox::information(this, "中国象棋", "您的对手超时了！您赢了！！！", QMessageBox::Ok);
        gameEnd();
    }
}

void MainWindow::on_actionLoad_file_triggered()
{
    if (!network->isConnected()) {
        QMessageBox::information(this, "中国象棋", "请先建立连接。", QMessageBox::Ok);
        return;
    }
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load"), ".");
    if (!fileName.isEmpty()){
        gameEnd();
        loadFile(fileName);
        QString str = (first == Red) ? "红方" : "黑方";
        QMessageBox::information(this, "载入残局", str + "先走。", QMessageBox::Ok);
    }
}

void MainWindow::on_actionSave_file_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存棋局"), ".");
    if (!fileName.isEmpty()){
        saveFile(fileName);
    }
}


void MainWindow::loadFile(const QString &fileName) {
    ChessInfo *info = new ChessInfo[2];
    std::ifstream fin(fileName.toStdString().c_str());
    for (int i = 0; i < 2; i++) {
        std::string sideName;
        fin >> sideName;
//        std::cout << sideName << std::endl;
        int sideI;
        if (sideName == "red") {
            if (i == 0) first = Red;
            sideI = 0;
        }
        else {
            if (i == 0) first = Black;
            sideI = 1;
        }
        char t1, t2, t3;
        int num, x, y;
        /*king*/
        fin >> num;
        fin >> t1 >> x >> t2 >> y >> t3;
        std::vector<Info> v;
        Info temp = { x, y ,1 };
        v.push_back(temp);
        info[sideI].push_back(v);
        /*other*/
        for (int j = 0; j < 5; j++) {
            fin >> num;
            std::vector<Info> vt;
            for (int k = 0; k < num; k++) {
                fin >> t1 >> x >> t2 >> y >> t3;
                Info temp = { x, y ,1 };
                vt.push_back(temp);
            }
            while (vt.size() < 2)
                vt.push_back(Info());
            info[sideI].push_back(vt);
        }
        /*pawn*/
        fin >> num;
        std::vector<Info> vt;
        for (int k = 0; k < num; k++) {
            fin >> t1 >> x >> t2 >> y >> t3;
            Info temp = { x, y ,1 };
            vt.push_back(temp);
        }
        while (vt.size() < 5)
            vt.push_back(Info());
        info[sideI].push_back(vt);
    }
    fileLoaded = true;
    chessboard->createChessBoard(chessboard->getSide(), info);
    gameCreated = true;
}

void MainWindow::saveFile(const QString& filename) {
    ChessInfo *info = chessboard->getChessInfo();
    std::ofstream fout(filename.toStdString());
    int ii[2];
    if (chessboard->isTurn()) {
//        std::cout << "isturn" << std::endl;
        if (chessboard->getSide() == Red) {std::cout << "red" << std::endl; ii[0] = 0; ii[1] = 1; }
        else {std::cout << "black" << std::endl; ii[0] = 1; ii[1] = 0; }
    } else {
        std::cout << "noturn" << std::endl;
        if (chessboard->getSide() == Red) {std::cout << "red" << std::endl; ii[0] = 1; ii[1] = 0; }
        else {std::cout << "black" << std::endl; ii[0] = 0; ii[1] = 1; }
    }
    for (int i = 0; i < 2; i++) {
        if (ii[i] == 0) fout << "red\n";
        else fout << "black\n";
        for (int j = 0; j < info[ii[i]].size(); j++) {
            int num = 0;
            for (int k = 0; k < info[ii[i]][j].size(); k++) {
                if (info[ii[i]][j][k].exist) num++;
            }
            fout << num << " ";
            for (int k = 0; k < info[ii[i]][j].size(); k++) {
                if (info[ii[i]][j][k].exist) {
                    if (chessboard->getSide() == Red) fout << "<" << info[ii[i]][j][k].x << "," << info[ii[i]][j][k].y << "> ";
                    else fout << "<" << 8 - info[ii[i]][j][k].x << "," << 9 - info[ii[i]][j][k].y << "> ";
                }
            }
            fout << "\n";
        }
    }
}

void MainWindow::start() {
    chessboard->setStart(true);
    chessboard->setEnd(false);
    admitButton->setEnabled(true);
    if (chessboard->getSide() == first) myTurn();
}

void MainWindow::win() {
    gameEnd();
    QMessageBox::information(this, "中国象棋", "您赢了！！！", QMessageBox::Ok);
}

void MainWindow::lose() {
    gameEnd();
    QMessageBox::information(this, "中国象棋", "您输了...", QMessageBox::Ok);
}

void MainWindow::timeOut() {
    gameEnd();
    coder->newSloMessage("timeOut");
    QMessageBox::information(this, "中国象棋", "时间到，您输了...", QMessageBox::Ok);
}

void MainWindow::admit() {
    if (!network->isConnected()) return;
    int r = QMessageBox::warning(this, "中国象棋", "您确定要认输吗？", QMessageBox::Yes | QMessageBox::No);
    if (r == QMessageBox::Yes) {
        coder->newSloMessage("admit");
        lose();
    }
}

void MainWindow::checking() {
    std::cout << "Checking" << std::endl;
    player->play();
}

void MainWindow::disconnect() {
    coder->newSloMessage("leave");
    network->setConnected(false);
}

void MainWindow::myTurn() {
    if (chessboard->isEnd() || !chessboard->isStart()) return;
    resetTime();
    timming = true;
    chessboard->setTurn(true);
}

void MainWindow::oneMove() {
    resetTime();
    timming = false;
    chessboard->setTurn(false);
}

void MainWindow::oppoOneMove() {
    myTurn();
}

void MainWindow::resetTime() {
    timeValue = timeLimit;
    lcd->display(timeLimit);
}

void MainWindow::readyStart() {
    resetTime();
    startButton->setEnabled(true);
    newGameButton->setEnabled(false);
    endgameButton->setEnabled(false);
    gameCreated = true;
}

void MainWindow::gameEnd() {
    startButton->setEnabled(false);
    admitButton->setEnabled(false);
    newGameButton->setEnabled(true);
    endgameButton->setEnabled(true);
    chessboard->setEnd(true);
    chessboard->setStart(false);
    meStart = false;
    oppoStart = false;
    timming = false;
    fileLoaded = false;
    gameCreated = false;
    resetTime();
}


void MainWindow::on_action_triggered()
{
    QMessageBox::information(this, "关于中国象棋", "这是一款简易的中国象棋网络对战游戏，岂不美哉！！！\n作者：顾煜贤 清华大学计算机科学与技术系", QMessageBox::Ok);
}

void MainWindow::on_action_Qt_triggered()
{
    qApp->aboutQt();
}
