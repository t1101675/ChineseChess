#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <vector>
#include <QPixmap>

enum Type { King, Guard, Bishop, Knight, Rook, Cannon, Pawn, None };
enum Side { Red, Black };

class Chessman;

typedef std::vector<Chessman*> EatChess;
typedef std::vector<QPoint> ValidPos;

struct Info {
  int x;
  int y;
  bool exist;  

  Info(int xx = 0, int yy = 0, bool ee = 0): x(xx), y(yy), exist(ee) {}
};

typedef std::vector<std::vector<Info> > ChessInfo;

class Chessman : public QWidget
{
    Q_OBJECT

public:
    Chessman(QWidget *parent = nullptr, Type type = King, Side side = Red, int x = 0, int y = 0);

    static const int length;
    static const int littleOffset;

    void setType(Type type) { this->type = type; }
    void setPos(const QPoint &pos) { this->x = pos.x(); this->y = pos.y(); }
    void setPos(int x, int y) { this->x = x; this->y = y; }
    void setClicked(bool clicked) { this->clicked = clicked; update(); }
    void setExist(bool exist) { this->exist = exist; if (!exist) { this->hide(); setPos(100, 100);} }
    void setSide(Side side) { this->side = side; }
    void setEatChess(EatChess &v) { eatChess = v; }
    void setValidPos(ValidPos &v) { validPos = v; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setInfo(const Info &info, Type type = King, Side side = Red) { setPos(info.x, info.y); setExist(info.exist); setType(type); setSide(side); setClicked(false);}

    int getX() const { return x; }
    int getY() const { return y;}
    QPoint getP() const { return QPoint(x, y); }
    Type getType() const { return type; }
    QPoint getPos() const { return QPoint(x, y); }
    Side getSide() const { return side; }
    EatChess getEatChess() const { return eatChess; }
    ValidPos getValidPos() const { return validPos; }
    Info getInfo() const { return Info(x, y, exist); }

    bool isClicked() const { return clicked; }
    bool isExist() const { return exist; }
    bool at(const QPoint &p) const { return p == QPoint(x, y); }
    bool at(int x, int y) const { return this->x == x && this->y == y; }

    void drawChess();
    void drawPress();


    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QSize sizeHint() const;

private:
    Side side;          //color
    Type type;          //type
    int x, y;           //position
    bool clicked;       //whether select
    bool exist;         //whether exist
    ValidPos validPos;  //position can reach
    EatChess eatChess;  //chessmans that can eat
    QPixmap *pm;

    bool inCircle(const QPoint &c, int r, const QPoint &p);
    void initial(Type type, Side side, int x, int y);
    QString getPixmap();

signals:

public slots:

};

#endif // CHESSMAN_H
