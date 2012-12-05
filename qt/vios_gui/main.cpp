#include "vios_gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViosGui w;
    w.show();

    return a.exec();
}
