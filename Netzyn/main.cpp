#include <QCoreApplication>
#include "netzynserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetzynServer netzyn;
    netzyn.startServer();

    return a.exec();
}
