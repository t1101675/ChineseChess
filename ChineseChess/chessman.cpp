#include "chessman.h"
#include <QPixmap>
#include <cmath>
#include <iostream>
#include <QBitmap>
#include <QRegion>

const int Chessman::length = 80;
const int Chessman::littleOffset = 2;
Chessman::Chessman(QWidget *parent, Type type, Side side, int x, int y) : QWidget(parent)
{
    initial(type, side, x, y);
    pm = new QPixmap(getPixmap());
    QRegion region(0, 0, length + 2 * littleOffset, length + 2 * littleOffset, QRegion::Ellipse);
    setMask(region);
}

void Chessman::paintEvent(QPaintEvent *event) {
    drawChess();
    drawPress();
}

void Chessman::mousePressEvent(QMouseEvent *event) {
    clicked = !clicked;
    update();
}

void Chessman::mouseMoveEvent(QMouseEvent *event) {

}

void Chessman::drawChess() {
   if (clicked || !exist) return;
   QPainter painter(this);
   painter.drawPixmap(littleOffset, littleOffset, length, length, *pm);
}

void Chessman::drawPress() {
    if (!clicked || !exist) return;
    QPainter painter(this);
    painter.drawPixmap(littleOffset, littleOffset, length, length, *pm);
    painter.setPen(QPen(Qt::green, 5));
    painter.drawEllipse(littleOffset, littleOffset, length, length);
}

QSize Chessman::sizeHint() const {
    return QSize(length + 4, length + 4);
}

QString Chessman::getPixmap() {
    QString dir(":/images/");
    QString pix;
    switch(type) {
    case King:
        if (side == Red) pix = "r_jiangshuai.png";
        else             pix = "b_jiangshuai.png";
        break;
    case Guard:
        if (side == Red) pix = "r_shi.png";
        else             pix = "b_shi.png";
        break;
    case Bishop:
        if (side == Red) pix = "r_xiang.png";
        else             pix = "b_xiang.png";
        break;
    case Knight:
        if (side == Red) pix = "r_ma.png";
        else             pix = "b_ma.png";
        break;
    case Rook:
        if (side == Red) pix = "r_ju.png";
        else             pix = "b_ju.png";
        break;
    case Cannon:
        if (side == Red) pix = "r_pao.png";
        else             pix = "b_pao.png";
        break;
    case Pawn:
        if (side == Red) pix = "r_zubing.png";
        else             pix = "b_zubing.png";
        break;
    }
    return dir + pix;
}

void Chessman::initial(Type type, Side side, int x, int y) {
    this->type = type;
    this->side = side;
    this->x = x;
    this->y = y;
    clicked = false;
    exist = false;
}

bool Chessman::inCircle(const QPoint &c, int r, const QPoint &p) {
    return (p.x() - c.x()) * (p.x() - c.x()) + (p.y() - c.y()) * (p.y() - c.y()) <= r * r;
}
