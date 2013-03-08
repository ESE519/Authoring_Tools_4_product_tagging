#include "netzynclient.h"

NetzynClient::NetzynClient()
{
    socket = new QTcpSocket();
}

void NetzynClient::connectToServer(QString host, qint16 port){
    socket->connectToHost(host,port);
    socket->waitForConnected(2000);
    qDebug() << "Connected to Server";
}

void NetzynClient::sendToServer(QString & data){
    data = data + "\r\n\r\n\r\n";
    socket->write(data.toAscii());
    socket->waitForBytesWritten(2000);
    qDebug() << "Sent Data to Server";
}

void NetzynClient::receiveFromServer(QImage & image){
    socket->waitForReadyRead(2000);
    qDebug() << "Reading " << socket->bytesAvailable() << "bytes";
    parser = new DataParser();
    parser->getData(socket->readAll());
}

void NetzynClient::disconnectFromServer(){
    socket->close();
    qDebug() << "Disconnected from Server";
}

