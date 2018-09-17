#include "coder.h"
#include <iostream>
#include <QtEndian>
#include <vector>

Coder::Coder(QObject *parent) : QObject(parent) {
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
}

void Coder::enCode(const ChessInfo* info) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out << quint32(0) << quint8('i');
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < info[i].size(); j++) {
            for (unsigned int k = 0; k < info[i][j].size(); k++) {
                out << (quint32)info[i][j][k].x << (quint32)info[i][j][k].y << (quint8)info[i][j][k].exist;
            }
        }
    }
    out.device()->seek(0);
    out << quint32(block.size() - sizeof(quint32));
    emit newSigByte(block);
}

void Coder::enCode(QString str) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out << quint32(0) << quint8('m');
    out << str;
    out.device()->seek(0);
    out << quint32(block.size() - sizeof(quint32));
    emit newSigByte(block);
}

void Coder::deCode(QByteArray array) {
//    std::cout << "decode" << std::endl;
    QDataStream in(&array, QIODevice::ReadOnly);
    quint8 commandTemp, command;
    in >> commandTemp;
    command = qFromBigEndian(commandTemp);
    if (command == 'i') {
        deCodeInfo(array);
    }
    else if (command == 'm'){
//        std::cout << "message" << std::endl;
        deCodeMessage(array);
    }
}

void Coder::deCodeInfo(QByteArray array) {
//    std::cout << "size: " << array.size() << std::endl;
    QDataStream in(&array, QIODevice::ReadOnly);
    quint8 temp;
    in >> temp;
    for (int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < info[i].size(); j++) {
            for (unsigned int k = 0; k < info[i][j].size(); k++) {
                quint32 tx, ty;
                quint8 te;
                in >> tx >> ty >> te;
                info[i][j][k].x = tx;
                info[i][j][k].y = ty;
                info[i][j][k].exist = te;
//                std::cout << info[i][j][k].x << " " << info[i][j][k].y << " " <<info[i][j][k].exist << std::endl;
            }
        }
    }
    emit newSigInfo(info);
}

void Coder::deCodeMessage(QByteArray array) {
     QDataStream in(&array, QIODevice::ReadOnly);
     quint8 temp;
     in >> temp;
     QString str;
     in >> str;
     emit newSigMessage(str);
}

void Coder::newSloByte(QByteArray array) {
    deCode(array);
}

void Coder::newSloInfo(ChessInfo* info) {
    enCode(info);
}

void Coder::newSloMessage(QString str) {
    enCode(str);
}
