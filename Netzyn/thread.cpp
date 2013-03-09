#include "thread.h"

Thread::Thread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void Thread::run()
{
    qDebug() << socketDescriptor << "Spawning new thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << "Client Connected";
    exec();

}

void Thread::readyRead()
{
    qDebug() << socketDescriptor << socket->bytesAvailable() << " bytes available";
    QByteArray request,response,imgByteArray;
    QString inData;
    QDataStream out(&response,QIODevice::WriteOnly);
    request = socket->readAll();
    QDataStream in(&request,QIODevice::ReadOnly);

    in >> inData;
    qDebug() << socketDescriptor << "Data in : " << inData;
    if (inData == "SEND"){
        // Read image;
        QImage img;
        QImageReader reader("/home/rajeev/Desktop/image.jpg");
        reader.read(&img);

        // Serialize Image
        QBuffer buffer(&imgByteArray);
        img.save(&buffer, "PNG");
        imgByteArray = qCompress(imgByteArray);
        //qDebug() << socketDescriptor << "Compressed Data : " << imgByteArray.toHex();

        // Write Data
        out << (qint64)imgByteArray.size();
        out << imgByteArray;
        socket->write(response);
        qDebug() << socketDescriptor << "Image compressed QByteArray Size : " << imgByteArray.size() << endl;
        qDebug() << socketDescriptor << "Data written" << response.size() << "bytes";
    }
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected: ";
    socket->deleteLater();
    exit(0);
}
