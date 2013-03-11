#ifndef NETZYNSERVER_H
#define NETZYNSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "thread.h"

class NetzynServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit NetzynServer(QObject *parent = 0);
    void startServer();

signals:
    
public slots:

protected:
    void incomingConnection(int socketDescriptor);
    
};

#endif // NETZYNSERVER_H
