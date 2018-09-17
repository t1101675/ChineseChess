#include "chessboard.h"
#include "chessman.h"
#include <QPixmap>
#include <iostream>
#include <QPropertyAnimation>

const double Chessboard::gridLength = 100;
const double Chessboard::gapLength = Chessboard::gridLength;
const double Chessboard::mapYMargin = Chessboard::gridLength;
const double Chessboard::mapXMargin = Chessboard::gridLength;
const double Chessboard::mapHeight = 8 * Chessboard::gridLength + Chessboard::gapLength + 2 * Chessboard::mapYMargin;
const double Chessboard::mapWidth = 8 * Chessboard::gridLength + 2 * Chessboard::mapXMargin;
const QPoint Chessboard::d[4] = { QPoint(0, 1), QPoint(0, -1), QPoint(-1, 0), QPoint(1, 0) };
const QPoint Chessboard::d2[4] = { QPoint(1, 1), QPoint(-1, -1), QPoint(-1, 1), QPoint(1, -1) };
const double Chessboard::pressRegionLength = Chessboard::gridLength;
const double Chessboard::markLength = 0.2 * Chessboard::gridLength;

Chessboard::Chessboard(QWidget *parent) : QWidget(parent)
{
    initial();
}

void Chessboard::paintEvent(QPaintEvent *event) {
    drawBoard();
    drawValidPos(selectChess);
}

void Chessboard::mousePressEvent(QMouseEvent *event) {
//    std::cout << "OK" << std::endl;
}

bool Chessboard::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() != QEvent::MouseButtonPress && event->type() != QEvent::MouseButtonDblClick) return QWidget::eventFilter(watched, event);
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if (!start || end) return true;
    if (!turn) return true;
    if (QString(watched->metaObject()->className()) == "Chessman") {
        /*clicked on a chessman*/
        Chessman *clickedChess = static_cast<Chessman*>(watched);
        if (selectChess) {
            /*there is a chessman selected*/
           if (clickedChess->getSide() == side) {
               /*change select or clicked self*/
               if (clickedChess == selectChess) {
                   clearSelect();
                   update();
                   return true;
               }
               else {
                   clearSelect();
                   selectChess = clickedChess;
               }
           }
           else {
               /*eat or change select*/
               if (moveChess(selectChess, clickedChess->getPos())) {
                   //can eat
                   clickedChess->setExist(false);
                   clearSelect();
                   emitNeed = true;
                   updateGameState();
                   checkKingMeet(0);
               }
               else {
                   //can't eat, changed select
                   clearSelect();
                   selectChess = clickedChess;
               }
           }
        }
        else {
            /*no select*/
            selectChess = clickedChess;
        }
    }
    else {
        /*clicked outside*/
        QPoint press = press2Chess(mouseEvent->pos());
        if ((press.x() >= 0) && (press.y() >= 0)) {
            /*press at valid position*/
            if (selectChess) {
                /*there is a chessman selected*/
                if (moveChess(selectChess, press)) {
                    /*moved a chess*/
                    clearSelect();
                    emitNeed = true;
                    updateGameState();
                    checkKingMeet(0);
                }
                else {
                    /*can't move*/
                    clearSelect();
                }
            }
            else {
                /*no select*/
            }
        }
        else {
            /*press not valid*/
            if (selectChess) {
                /*there is select, clear*/
                clearSelect();
            }
            else {
                /*there is no select nothing happens*/
            }
        }
    }
    update();
    return QWidget::eventFilter(watched, event);
}

void Chessboard::createChessBoard(Side side) {
    setSide(side);
    this->created = true;
    initialChess();
    drawChess();
    updateGameState();
}

void Chessboard::createChessBoard(Side side, ChessInfo info[]) {
    setSide(side);
    this->created = true;
    initialChess();
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < info[i].size(); j++) {
//            std::cout << info[i][j].size() << std::endl;
            for (unsigned int k = 0; k < info[i][j].size(); k++) {
                this->info[i][j][k] = info[i][j][k];
                chessmans[i][j][k]->setX(info[i][j][k].x);
                chessmans[i][j][k]->setY(info[i][j][k].y);
                chessmans[i][j][k]->setExist(info[i][j][k].exist);
            }
        }
    }
    if (side == Black) rotate();
    drawChess();
    updateGameState();
}

void Chessboard::emitInfo() {
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < chessmans[i].size(); j++) {
            for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
                info[i][j][k].x = chessmans[i][j][k]->getX();
                info[i][j][k].y = chessmans[i][j][k]->getY();
                info[i][j][k].exist = chessmans[i][j][k]->isExist();
            }
        }
    }
    emit newSend(info);
}

ChessInfo* Chessboard::getChessInfo() {
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < chessmans[i].size(); j++) {
            for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
                info[i][j][k].x = chessmans[i][j][k]->getX();
                info[i][j][k].y = chessmans[i][j][k]->getY();
                info[i][j][k].exist = chessmans[i][j][k]->isExist();
            }
        }
    }
    return info;
}

void Chessboard::drawBoard() {
    QPainter painter(this);
    QPixmap mp(":/images/background.png");
    painter.drawPixmap(0, 0, mapWidth, mapHeight, mp);
}

void Chessboard::drawChess() {
//    std::cout << "Draw" << std::endl;
    for (int k = 0; k < 2; k++) {
        for (unsigned int i = 0; i < chessmans[k].size(); i++) {
            for (unsigned int j = 0; j < chessmans[k][i].size(); j++) {
                QPoint pos = chess2Board(chessmans[k][i][j]->getPos());
                chessmans[k][i][j]->setGeometry(pos.x(), pos.y(), chessmans[k][i][j]->sizeHint().width(), chessmans[k][i][j]->sizeHint().height());
                chessmans[k][i][j]->show();
            }
        }
    }
}

void Chessboard::newRead(ChessInfo *info) {
    this->created = true;
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < info[i].size(); j++) {
            for (unsigned int k = 0; k < info[i][j].size(); k++) {
                this->info[i][j][k] = info[i][j][k];
                chessmans[i][j][k]->setX(info[i][j][k].x);
                chessmans[i][j][k]->setY(info[i][j][k].y);
                chessmans[i][j][k]->setExist(info[i][j][k].exist);
            }
        }
    }
    rotate();
    drawChess();
    updateGameState();
    checkKingMeet(1);
}

void Chessboard::drawValidPos(Chessman *chess) {
    if (!chess) return;
    if (!chess->isClicked()) return;
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::blue));
    ValidPos v = chess->getValidPos();
    for (unsigned int i = 0; i < v.size(); i++) {
        QRect pressRegion = chess2PressRegion(v[i]);
        painter.save();
        painter.translate(pressRegion.x(), pressRegion.y());
        for (int i = 0; i < 4; i++) {
            QPoint point[3] = { QPoint(0, 0), QPoint(markLength, 0), QPoint(0, markLength) };
            painter.drawPolygon(point, 3);
            painter.translate(pressRegion.width() / 2, pressRegion.height() / 2);
            painter.rotate(90);
            painter.translate(-pressRegion.width() / 2, -pressRegion.height() / 2);
        }
        painter.restore();
//        painter.drawRect(chess2PressRegion(v[i]));
    }
}

QSize Chessboard::sizeHint() const {
    return QSize(mapWidth, mapHeight);
}

void Chessboard::initial() {
    chess2board.setX(0);
    chess2board.setY(0);

    board2World.setX(0);
    board2World.setY(0);

    side = Red;
    oppoSide = (side == Red) ? Black : Red;
    selectChess = NULL;
    emitNeed = false;
    start = false;
    end = false;
    turn = false;

    installEventFilter(this);

    /*initial info*/
    for (int i = 0; i < 2; i++) {
        std::vector<Info> v[7];
        v[0].push_back(Info());
        for (int j = 1; j <= 5; j++) {
            v[j].push_back(Info());
            v[j].push_back(Info());
        }
        for (int k = 0; k < 5; k++) {
            v[6].push_back(Info());
        }
        for (int l = 0; l < 7; l++) {
            info[i].push_back(v[l]);
        }
    }
    /*initial chess*/
    Chessman *chess;
    for (int i = 0; i < 2; i++) {
        Side side = (i == 0) ? Red : Black;
        /*King*/
        std::vector<Chessman*> vKing;
        chess = new Chessman(this, King, side, 0, 0);
        chess->installEventFilter(this);
        vKing.push_back(chess);
        chessmans[i].push_back(vKing);
        /*other*/
        for (int j = 1; j <= 5; j++) {
            Type type = Type(j);
            std::vector<Chessman*> vOther;
            for (int k = 0; k < 2; k++) {
                chess = new Chessman(this, type, side, 0, 0);
                chess->installEventFilter(this);
                vOther.push_back(chess);
            }
            chessmans[i].push_back(vOther);
        }
        /*Pawn*/
        std::vector<Chessman*> vPawn;
        for (int j = 0; j < 5; j++) {
            chess = new Chessman(this, Pawn, side, 0, 0);
            chess->installEventFilter(this);
            vPawn.push_back(chess);
        }
        chessmans[i].push_back(vPawn);
    }
}

void Chessboard::initialChess() {
    for (int i = 0; i < 2; i++) {
        Side side = (i == 0) ? Red : Black;
        int y1 = (i == 0) ? 0 : 9;
        int y2 = (i == 0) ? 2 : 7;
        int y3 = (i == 0) ? 3 : 6;
        /*King*/
        chessmans[i][0][0]->setInfo(Info(4, y1, 1), King, side);
        /*Guard*/
        chessmans[i][1][0]->setInfo(Info(3, y1, 1), Guard, side);
        chessmans[i][1][1]->setInfo(Info(5, y1, 1), Guard, side);
        /*Bishop*/
        chessmans[i][2][0]->setInfo(Info(2, y1, 1), Bishop, side);
        chessmans[i][2][1]->setInfo(Info(6, y1, 1), Bishop, side);
        /*Knight*/
        chessmans[i][3][0]->setInfo(Info(1, y1, 1), Knight, side);
        chessmans[i][3][1]->setInfo(Info(7, y1, 1), Knight, side);
        /*Rook*/
        chessmans[i][4][0]->setInfo(Info(0, y1, 1), Rook, side);
        chessmans[i][4][1]->setInfo(Info(8, y1, 1), Rook, side);
        /*Cannon*/
        chessmans[i][5][0]->setInfo(Info(1, y2, 1), Cannon, side);
        chessmans[i][5][1]->setInfo(Info(7, y2, 1), Cannon, side);
        /*Pawn*/
        for (int k = 0; k < 5; k++) {
            chessmans[i][6][k]->setInfo(Info(2 * k, y3, 1), Pawn, side);
        }
    }
    if (side == Black) rotate();
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < chessmans[i].size(); j++) {
            for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
                info[i][j][k].x = chessmans[i][j][k]->getX();
                info[i][j][k].y = chessmans[i][j][k]->getY();
                info[i][j][k].exist = chessmans[i][j][k]->isExist();
            }
        }
    }
}

bool Chessboard::moveChess(Chessman *chess, const QPoint &p) {
    bool canMove = false;
    ValidPos v = chess->getValidPos();
    for (unsigned int i = 0; i < v.size(); i++) {
        if (p == v[i]) canMove = true;
    }
    if (canMove) {
        QPoint oriPos = chess2Board(chess->getPos());
        chess->setPos(p);
        QPoint pos = chess2Board(chess->getPos());
        animate(chess, oriPos, pos);
//        chess->setGeometry(pos.x(), pos.y(), chess->sizeHint().width(), chess->sizeHint().height());
        emit oneMove();
        return true;
    }
    else return false;
}

void Chessboard::clearSelect() {
    selectChess->setClicked(false);
    selectChess = NULL;
}

QPoint Chessboard::chess2Board(const QPoint &point) const {
    return chess2Board(point.x(), point.y());
}

QPoint Chessboard::chess2Board(int x, int y) const {
    int xx = x * gridLength + mapXMargin - Chessman::length / 2 - Chessman::littleOffset;
    int yy = mapHeight - mapYMargin - y * gridLength - Chessman::length / 2 - Chessman::littleOffset;
    return QPoint(xx, yy);
}

QPoint Chessboard::press2Chess(const QPoint &point) const {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 10; y++) {
            if (chess2PressRegion(QPoint(x, y)).contains(point)) return QPoint(x, y);
        }
    }
    return QPoint(-1, -1);
}

QPoint Chessboard::press2Chess(int x, int y) const {
    return press2Chess(QPoint(x, y));
}

QRect Chessboard::chess2PressRegion(const QPoint &point) const {
    QPoint p = chess2Board(point);
    return QRect(p.x() + (gridLength - pressRegionLength) / 2 - 6, p.y() + (gridLength - pressRegionLength) / 2, pressRegionLength, pressRegionLength);
}

QRect Chessboard::chess2PressRegion(int x, int y) const {
    return chess2PressRegion(QPoint(x, y));
}

void Chessboard::rotate() {
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < chessmans[i].size(); j++) {
            for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
                chessmans[i][j][k]->setX(8 - chessmans[i][j][k]->getX());
                chessmans[i][j][k]->setY(9 - chessmans[i][j][k]->getY());
            }
        }
    }
}

void Chessboard::checkKingMeet(bool result) {
    Chessman *king;
    king = chessmans[int(side)][0][0];
    QPoint next = king->getPos();
    while (inMap(next)) {
        Chessman *chess = whichAt(next);
        if (chess && chess != king) {
            if (chess->getType() == King) {
                if (result == 0) emit lose();
                else emit win();
            }
            break;
        }
        next = next + QPoint(0, 1);
    }
}

void Chessboard::animate(Chessman *chess, QPoint start, QPoint end) {
    QPropertyAnimation *anim = new QPropertyAnimation(chess, "pos");
    anim->setDuration(500);
    anim->setStartValue(start);
    anim->setEndValue(end);
    anim->setEasingCurve(QEasingCurve::InOutQuad);
    anim->start();
}

Chessman* Chessboard::whichAt(int x, int y) {
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < chessmans[i].size(); j++) {
            for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
                if (chessmans[i][j][k]->isExist() && (chessmans[i][j][k]->getPos() == QPoint(x, y))) {
                    return chessmans[i][j][k];
                }
            }
        }
    }
    return NULL;
}

Chessman* Chessboard::whichSelect() {
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < chessmans[i].size(); j++) {
            for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
                if (chessmans[i][j][k]->isExist() && chessmans[i][j][k]->isClicked()) {
                    return chessmans[i][j][k];
                }
            }
        }
    }
    return NULL;
}

void Chessboard::updateGameState() {
    int i = int(side);
    for (unsigned int j = 0; j < chessmans[i].size(); j++) {
        for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
            switch(chessmans[i][j][k]->getType()) {
            case King: updateKing(chessmans[i][j][k]); break;
            case Guard: updateGuard(chessmans[i][j][k]); break;
            case Bishop: updateBishop(chessmans[i][j][k]); break;
            case Knight: updateKnight(chessmans[i][j][k]); break;
            case Rook: updateRook(chessmans[i][j][k]); break;
            case Cannon: updateCannon(chessmans[i][j][k]); break;
            case Pawn:updatePawn(chessmans[i][j][k]); break;
            default: continue; break;
            }
        }
    }

    if (emitNeed) {
        for (int i = 0; i < 2; i++) {
            for (unsigned int j = 0; j < chessmans[i].size(); j++) {
                for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
                    info[i][j][k].x = chessmans[i][j][k]->getX();
                    info[i][j][k].y = chessmans[i][j][k]->getY();
                    info[i][j][k].exist = chessmans[i][j][k]->isExist();
                }
            }
        }
        emit newSend(info);
        emitNeed = false;
    }
    for (unsigned int j = 0; j < chessmans[i].size(); j++) {
        for (unsigned int k = 0; k < chessmans[i][j].size(); k++) {
            EatChess e = chessmans[i][j][k]->getEatChess();
            for (unsigned int m = 0; m < e.size(); m++) {
                if (chessmans[i][j][k]->isExist() && e[m]->getType() == King) {
                    emit checking();
                    break;
                }
            }
        }
    }
//    std::cout << side << " " << oppoSide << std::endl;
    if (!chessmans[i][0][0]->isExist()) {
//        std::cout << "lose" << std::endl;
        emit lose();
    }
    if (!chessmans[int(oppoSide)][0][0]->isExist()) {
//        std::cout << "win" << std::endl;
        emit win();
    }
}

/*King, Guard, Bishop, Knight, Rook, Cannon, Pawn, None*/
void Chessboard::updateKing(Chessman *king) {
//    std::cout << "King" << std::endl;
    ValidPos v;
    EatChess e;
    if (king->at(4, 1)) {
        Chessman *chess[8];
        QPoint next[8] = { QPoint(3, 1), QPoint(5, 1), QPoint(4, 2), QPoint(4, 0), QPoint(3, 2), QPoint(5, 2), QPoint(3, 0), QPoint(5, 0) };
        for (int i = 0; i < 8; i++) {
            chess[i] = whichAt(next[i]);
            if (chess[i]) {
                if (chess[i]->getSide() != side) {
                    e.push_back(chess[i]);
                    v.push_back(next[i]);
                }
            }
            else v.push_back(next[i]);
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            QPoint next = king->getPos() + d[i];
            if ((3 <= next.x()) && (next.x() <= 5) && (0 <= next.y()) && (next.y() <= 2)) {
                Chessman *chess = whichAt(next);
                if (chess) {
                    if (chess->getSide() != side) {
                        e.push_back(chess);
                        v.push_back(next);
                    }
                }
                else v.push_back(next);
            }
        }
        Chessman *chess = whichAt(4, 1);
        if (chess) {
            if (chess->getSide() != side) {
                e.push_back(chess);
                v.push_back(QPoint(4, 1));
            }
        }
        else v.push_back(QPoint(4, 1));
    }
    king->setValidPos(v);
    king->setEatChess(e);
}

void Chessboard::updateGuard(Chessman *guard) {
    ValidPos v;
    EatChess e;
    if (guard->at(4, 1)) {
        Chessman *chess[8];
        QPoint next[8] = { QPoint(3, 1), QPoint(5, 1), QPoint(4, 2), QPoint(4, 0), QPoint(3, 2), QPoint(5, 2), QPoint(3, 0), QPoint(5, 0) };
        for (int i = 0; i < 8; i++) {
            chess[i] = whichAt(next[i]);
            if (chess[i]) {
                if (chess[i]->getSide() != side) {
                    e.push_back(chess[i]);
                    v.push_back(next[i]);
                }
            }
            else v.push_back(next[i]);
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            QPoint next = guard->getPos() + d[i];
            if ((3 <= next.x()) && (next.x() <= 5) && (0 <= next.y()) && (next.y() <= 2)) {
                Chessman *chess = whichAt(next);
                if (chess) {
                    if (chess->getSide() != side) {
                        e.push_back(chess);
                        v.push_back(next);
                    }
                }
                else v.push_back(next);
            }
        }
        Chessman *chess = whichAt(4, 1);
        if (chess) {
            if (chess->getSide() != side) {
                e.push_back(chess);
                v.push_back(QPoint(4, 1));
            }
        }
        else v.push_back(QPoint(4, 1));
    }
    guard->setValidPos(v);
    guard->setEatChess(e);
}

void Chessboard::updateBishop(Chessman *bishop) {
    ValidPos v;
    EatChess e;
    QPoint pos = bishop->getPos();
    for (int i = 0; i < 4; i++) {
        QPoint next = pos + 2 * d2[i];
        if (next.y() > 4) continue;
        Chessman *chess = whichAt(next);
        if (chess && (chess != bishop)) {
            if (chess->getSide() != side) {
                e.push_back(chess);
                v.push_back(next);
            }
        }
        else if (chess != bishop) v.push_back(next);
    }
    bishop->setValidPos(v);
    bishop->setEatChess(e);
}

void Chessboard::updateRook(Chessman *rook) {
    ValidPos v;
    EatChess e;
    QPoint pos = rook->getPos();
    for (int i = 0; i < 4; i++) {
        QPoint next = pos;
        while (inMap(next)) {
            Chessman *chess = whichAt(next);
            if (chess && (chess != rook)) {
                if (chess->getSide() != side) {
                    e.push_back(chess);
                    v.push_back(next);
                }
                break;
            }
            else if (chess != rook) v.push_back(next);
            next = next + d[i];
        }
    }
    rook->setValidPos(v);
    rook->setEatChess(e);
}

void Chessboard::updateKnight(Chessman *knight) {
    ValidPos v;
    EatChess e;
    QPoint pos = knight->getPos();
    for (int i = 0; i < 4; i++) {
        QPoint next1 = pos + d[i];
        if (!whichAt(next1)) {
            QPoint next2[2];
            if (d[i].x() != 0) {
                next2[0] = next1 + QPoint(d[i].x(), 1);
                next2[1] = next1 + QPoint(d[i].x(), -1);
            } else {
                next2[0] = next1 + QPoint(1, d[i].y());
                next2[1] = next1 + QPoint(-1, d[i].y());
            }
            for (int j = 0; j < 2; j++) {
                if (!inMap(next2[j])) continue;
                Chessman *chess = whichAt(next2[j]);
                if (chess) {
                    if (chess->getSide() != side) {
                        e.push_back(chess);
                        v.push_back(next2[j]);
                    }
                }
                else v.push_back(next2[j]);
            }
        }
    }
    knight->setValidPos(v);
    knight->setEatChess(e);
}

void Chessboard::updateCannon(Chessman *cannon) {
    ValidPos v;
    EatChess e;
    QPoint pos = cannon->getPos();
    for (int i = 0; i < 4; i++) {
        QPoint next = pos;
        while(inMap(next)) {
            Chessman* chess = whichAt(next);
            if (chess && (chess != cannon)) {
                break;
            }
            else if (chess != cannon) {
                v.push_back(next);
            }
            next = next + d[i];
        }
        next = next + d[i];
        while(inMap(next)) {
            Chessman* chess = whichAt(next);
            if (chess) {
                if (chess->getSide() != side) {
                    v.push_back(next);
                    e.push_back(chess);
                }
                break;
            }
            next = next + d[i];
        }
    }
    cannon->setValidPos(v);
    cannon->setEatChess(e);
}

void Chessboard::updatePawn(Chessman *pawn) {
    ValidPos v;
    EatChess e;
    QPoint pos = pawn->getPos();
    if (pos.y() <= 4) {
        QPoint next = pos + QPoint(0, 1);
        Chessman* chess = whichAt(next);
        if (chess) {
            if (chess->getSide() != side) {
                v.push_back(next);
                e.push_back(chess);
            }
        } else {
            v.push_back(next);
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            QPoint next = pos + d[i];
            if (d[i] == QPoint(0, -1)) continue;
            if (inMap(next)) {
                Chessman* chess = whichAt(next);
                if (chess) {
                    if (chess->getSide() != side) {
                        v.push_back(next);
                        e.push_back(chess);
                    }
                }
                else {
                    v.push_back(next);
                }
            }
        }
    }
    pawn->setValidPos(v);
    pawn->setEatChess(e);
}

