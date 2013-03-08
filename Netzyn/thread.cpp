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
    QByteArray request =socket->readAll();
    DataParser * parser = new DataParser(request);
    parser->removeTerminator();
    qDebug() << socketDescriptor << "Data in" << parser->data;
    if (parser->data == "SEND"){
        QImage img;
        QImageReader reader("/home/rajeev/Desktop/image.jpg");
        reader.read(&img);
        parser->serializeImage(img);
        qDebug() << parser->byteData.size();
        socket->write(parser->byteData);
        qDebug() << socketDescriptor << "Data written" << parser->byteData.size() << "bytes";
    }
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected: ";
    socket->deleteLater();
    exit(0);
}
