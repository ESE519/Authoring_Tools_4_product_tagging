#include "frame.h"
#include <QApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frame w;
    w.show();
    
    server myServer;
    myServer.startServer();

    return a.exec();
}
