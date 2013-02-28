#include "thread.h"
#include "dataparser.h"

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
    char * cdata;
    DataParser * parser = new DataParser();
    qDebug() << socketDescriptor << "Data in" << request;
    cdata = request.data();
    parser->getData(cdata);
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected: ";
    socket->deleteLater();
    exit(0);
}
