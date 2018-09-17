#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork/QTcpSocket>

class ClientSocket : public QTcpSocket{
public:
    ClientSocket(QObject *parent = 0);

    void connectServer();

private slots:
    void readMessage();

private:
    void sendMessage();
};

#endif // CLIENTSOCKET_H
