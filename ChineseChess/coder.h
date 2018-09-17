#ifndef CODER_H
#define CODER_H

#include <QObject>
#include <QDataStream>
#include <QByteArray>
#include <vector>
#include "chessman.h"
/*King, Guard, Bishop, Knight, Rook, Cannon, Pawn, None*/
/*0    x    y   exist */
/*32 + 32 + 32 + 8    */

class Coder : public QObject
{
    Q_OBJECT
public:
    explicit Coder(QObject *parent = nullptr);
    void enCode(QString str);
    void enCode(const ChessInfo* info);
    void deCode(QByteArray array);
    void deCodeInfo(QByteArray array);
    void deCodeMessage(QByteArray array);
    void setSide(Side side) { this->side = side; }
    ChessInfo info[2];

private:
    Side side;

signals:
    void newSigByte(QByteArray array);
    void newSigInfo(ChessInfo* info);
    void newSigMessage(QString str);

public slots:
    void newSloByte(QByteArray array);
    void newSloInfo(ChessInfo* info);
    void newSloMessage(QString str);
};

#endif // CODER_H
