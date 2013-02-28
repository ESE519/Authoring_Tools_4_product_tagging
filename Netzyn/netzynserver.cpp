#include "netzynserver.h"

NetzynServer::NetzynServer(QObject *parent) :
    QTcpServer(parent)
{
}

void NetzynServer::startServer()
{
    if(!this->listen(QHostAddress::Any,1234))
        qDebug()<<"Cannot start server";
    else
        qDebug()<<"Listening";
}

void NetzynServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << "Connecting";
    Thread * newThread= new Thread(socketDescriptor,this);
    connect(newThread, SIGNAL(finished()),newThread,SLOT(deleteLater()));
    newThread->start();
}
