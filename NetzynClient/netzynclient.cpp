#include "netzynclient.h"

NetzynClient::NetzynClient(QObject * parent)
{
}

void NetzynClient::connectToServer(QString host, qint16 port){
    qDebug() << "Entered connectToServer";
    socket = new QTcpSocket();
    in.setDevice(socket);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    socket->connectToHost(host,port);
    socket->waitForConnected(2000);
    qDebug() << "Connected to Server";
}

void NetzynClient::sendToServer(QString & data){
    QByteArray outData;
    QDataStream out(&outData,QIODevice::WriteOnly);
    out << data;
    socket->write(outData);
    qDebug() << "Sent Data to Server";
}

void NetzynClient::receiveFromServer(QImage & image){
    inData = inData.right(inData.size()-4);
    qDebug() << "QByteArray Uncompress input Size : " << inData.size();
    //qDebug() << "Compressed Data : " << inData.toHex();
    inData = qUncompress(inData);
    QBuffer buffer(&inData);
    image.load(&buffer, "PNG");
    qDebug() << "Image Size : " << image.size();
    emit updateScene();
}

void NetzynClient::disconnectFromServer(){
    socket->close();
    qDebug() << "Disconnected from Server";
}

void NetzynClient::readyRead(){
    static qint64 byteCount = 0;
    QByteArray tmp;
    qDebug() << "socket byteAvailable : " << socket->bytesAvailable();
    if (byteCount == 0){
        byteCount += (qint64)socket->bytesAvailable() - sizeof(qint64);
        in >> packetByteCount;
        tmp = socket->readAll();
        qDebug() << "packetByteCount : " << packetByteCount;
        inData = NULL;
    }
    else{
        byteCount += (qint64)socket->bytesAvailable();
        tmp = socket->readAll();
    }
    inData += tmp;
    qDebug() << "Current byteCount : " << byteCount;
    qDebug() << "inData QByteArray size: " << inData.size();
    if (byteCount >= packetByteCount){
        qDebug() << "inData Size : " << inData.size();
        receiveFromServer(frame);
        byteCount = 0;
        packetByteCount = 0;
    }
}

void NetzynClient::disconnected()
{
    qDebug() << "Disconnected: ";
    socket->deleteLater();
}
