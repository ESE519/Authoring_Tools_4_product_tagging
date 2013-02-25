#include "server.h"

server::server(QObject *parent) :
    QTcpServer(parent)
{
}

void server::startServer()
{
    if(!this->listen(QHostAddress::Any,1234))
    {
        qDebug()<<"Cannot start server";
    }
    else
        qDebug()<<"Listening";
}

void server::incomingConnection(int socketDescriptor)
{
    qDebug()<<socketDescriptor<<"connecting";
    Thread *myThread= new Thread(socketDescriptor,this);
    connect(myThread, SIGNAL(finished()),myThread,SLOT(deleteLater()));
    myThread->start();
}
