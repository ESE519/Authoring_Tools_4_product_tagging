#ifndef NETZYNCLIENT_H
#define NETZYNCLIENT_H

#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>
#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <QObject>

class NetzynClient : public QObject
{
    Q_OBJECT
public:
    explicit NetzynClient(QObject * parent = 0);

signals:
    void error(QTcpSocket::SocketError socketError);

public:
    void connectToServer(QString host, qint16 port);
    void disconnectFromServer();
    void sendToServer(QString &data);
    void receiveFromServer(QImage & image);

signals:
    //void updateScene();

private slots:
    void readyRead();
    void disconnected();

private:
    QDataStream in;
    QByteArray inData;
    qint64 packetByteCount;

public:
    QImage overlayFrame;
    QTcpSocket * socket;
};

#endif // NETZYNCLIENT_H
