#include "network.h"
#include <QDataStream>
#include <iostream>
#include <memory.h>
#include <QtEndian>
#include <QAbstractSocket>

Network::Network(QObject *parent) : QObject(parent)
{
    type = Server;
    nextSize = 0;
    connected = false;
    listenSocket = NULL;
    readWriteSocket = NULL;
}

void Network::setNetwork(NetworkType type, const QString &IP, int port) {
    this->type = type;
    if (type == Server) initialServer(IP, port);
    else initialClient(IP, port);
}

void Network::initialServer(const QString &IP, int port) {
    listenSocket = new QTcpServer(this);
    listenSocket->listen(QHostAddress::Any, port);
    connect(listenSocket, SIGNAL(newConnection()), this, SLOT(newServerConnect()));
}

void Network::initialClient(const QString &IP, int port) {
    readWriteSocket = new QTcpSocket(this);
    connect(readWriteSocket, SIGNAL(connected()), this, SLOT(newClientConnect()));
    readWriteSocket->connectToHost(QHostAddress(IP), port);
}

void Network::newServerConnect() {
    if (!listenSocket) return;
    connected = true;
    emit serverConnect();
    readWriteSocket = listenSocket->nextPendingConnection();
    connect(readWriteSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}

void Network::newClientConnect() {
    std::cout << "client connect" << std::endl;
    connected = true;
    emit clientConnect();
    connect(readWriteSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}

void Network::readMessage() {
    if (!readWriteSocket) return;
    while (true) {
        if (nextSize == 0) {
            if (readWriteSocket->bytesAvailable() < sizeof(quint32)) return;
            QByteArray data = readWriteSocket->read(sizeof(quint32));
            nextSize = qFromBigEndian<quint32>(data.data());
        }
        if (readWriteSocket->bytesAvailable() < nextSize) {
            return;
        }
        array = readWriteSocket->read(nextSize);
        emit newRead(array);
        nextSize = 0;
    }
}

void Network::sendMessage(QByteArray array) {
    if (!readWriteSocket) return;
    readWriteSocket->write(array);
//    std::cout << "sent" << std::endl;
}

void Network::newSend(QByteArray array) {
    sendMessage(array);
}

void Network::startServer(QString IP, int port) {
   setNetwork(Server, IP, port);
}

void Network::startClient(QString IP, int port) {
    setNetwork(Client, IP, port);
}

void Network::endServer() {
    if (!listenSocket) return;
    listenSocket->close();
}

void Network::endClient() {
    if (!readWriteSocket) return;
    readWriteSocket->close();
}
