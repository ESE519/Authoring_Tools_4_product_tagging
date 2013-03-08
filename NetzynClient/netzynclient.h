#ifndef NETZYNCLIENT_H
#define NETZYNCLIENT_H

#include <QTcpSocket>
#include <QDebug>
#include "dataparser.h"

class NetzynClient
{
public:
    NetzynClient();
signals:
    void error(QTcpSocket::SocketError socketError);

public:
    void connectToServer(QString host, qint16 port);
    void disconnectFromServer();
    void sendToServer(QString &data);
    void receiveFromServer(QImage & image);
    DataParser * parser;

private:
    QTcpSocket * socket;

};

#endif // NETZYNCLIENT_H
