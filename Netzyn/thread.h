#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>
#include <QTcpSocket>
#include <QImage>
#include <QImageReader>
#include <QDataStream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QBuffer>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(int ID, QObject *parent = 0);
    void run();
    QTcpSocket * socket;
    int socketDescriptor;
    QDataStream in;

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:
    void readyRead();
    void disconnected();

};

#endif // THREAD_H
