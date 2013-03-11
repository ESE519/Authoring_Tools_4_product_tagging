#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QDebug>
#include "thread.h"

class server : public QTcpServer
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    void startServer();

signals:
    
public slots:
    
protected:
    void incomingConnection(int socketDescriptor);

};

#endif // SERVER_H
