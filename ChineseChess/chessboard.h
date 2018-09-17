#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include "chessman.h"
#include <QPaintEvent>
#include <vector>
#include <QTransform>
#include <iostream>

class Chessboard : public QWidget
{
    Q_OBJECT
public:
    explicit Chessboard(QWidget *parent = nullptr);

    static const double mapHeight;
    static const double mapWidth;
    static const double mapXMargin;
    static const double gridLength;
    static const double gapLength;
    static const double mapYMargin;
    static const double pressRegionLength;
    static const double markLength;
    static const QPoint d[4];
    static const QPoint d2[4];

    Side getSide() const { return side; }
    bool isCreated() const { return created; }
    bool isStart() const { return start; }
    bool isEnd() const { return end; }
    bool isTurn() const { return turn; }

    void setSide(Side side) {
        this->side = side;
        oppoSide = (side == Red) ? Black : Red;
    }
    void setCreate(bool created) { this->created = created; }
    void setStart(bool start) { this->start = start; }
    void setEnd(bool end) { this->end = end; }
    void setTurn(bool turn) { this->turn = turn; }

    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    bool eventFilter(QObject *watched, QEvent *event);

    void createChessBoard(Side side);
    void createChessBoard(Side side, ChessInfo info[]);
    void emitInfo();

    ChessInfo* getChessInfo();

private:
    void initial();
    void initialChess();
    void drawBoard();
    void drawChess();
    void drawValidPos(Chessman *chess);
    void rotate();
    void checkKingMeet(bool result);
    void animate(Chessman *chess, QPoint start, QPoint end);

    QPoint chess2board;
    QPoint board2World;

    QPoint chess2Board(const QPoint &point) const;
    QPoint chess2Board(int x, int y) const;
    QPoint press2Chess(const QPoint &point) const;
    QPoint press2Chess(int x, int y) const;
    QRect chess2PressRegion(const QPoint &point) const;
    QRect chess2PressRegion(int x, int y) const;

    bool moveChess(Chessman* chess, const QPoint &p);
    bool valid(const QPoint &pos) const;
    bool valid(int x, int y) const;
    bool inMap(const QPoint &p) { return inMap(p.x(), p.y()); }
    bool inMap(int x, int y) { return (0 <= x) && (x <= 8) && (0 <= y) && (y <= 9); }

    void clearSelect();
    void updateGameState();
    void updateChessState(Chessman *chess);
    /*King, Guard, Bishop, Knight, Rook, Cannon, Pawn*/
    void updateKing(Chessman *king);
    void updateGuard(Chessman *guard);
    void updateBishop(Chessman *bishop);
    void updateKnight(Chessman *knight);
    void updateRook(Chessman *rook);
    void updateCannon(Chessman *cannon);
    void updatePawn(Chessman *pawn);

    Chessman* whichAt(const QPoint &p) { return whichAt(p.x(), p.y()); }
    Chessman* whichAt(int x, int y);
    QSize sizeHint() const;
    std::vector< std::vector<Chessman*> > chessmans[2];
    ChessInfo info[2];

    Chessman* whichSelect();

    Side side;
    Side oppoSide;
    Chessman* selectChess;
    bool emitNeed;
    bool created;
    bool end;
    bool start;
    bool turn;


    QRect test[9][10];

signals:
    void newSend(ChessInfo* info);
    void oneMove();
    void checking();
    void win();
    void lose();

public slots:
    void newRead(ChessInfo* info);

};

#endif // CHESSBOARD_H
