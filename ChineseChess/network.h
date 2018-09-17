#ifndef NETWORD_H
#define NETWORD_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QByteArray>

enum NetworkType{ Server, Client };

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    QByteArray getByteArray() const { return array; }
    void setNetwork(NetworkType type, const QString &IP, int port);

    bool isConnected() const { return connected; }
    void setConnected(bool connected) { this->connected = connected; }
    NetworkType getType() const { return type; }

private:
    void initialServer(const QString &IP, int port);
    void initialClient(const QString &IP, int port);
    void sendMessage(QByteArray array);

    QTcpServer  *listenSocket;
    QTcpSocket  *readWriteSocket;
    NetworkType type;
    QByteArray array;

    quint32 nextSize;

    bool connected;

signals:
    void newRead(QByteArray);
    void clientConnect();
    void serverConnect();

public slots:
    void startServer(QString IP, int port);
    void startClient(QString IP, int port);
    void endServer();
    void endClient();
    void newServerConnect();
    void newClientConnect();
    void readMessage();
    void newSend(QByteArray array);

};

#endif // NETWORD_H
