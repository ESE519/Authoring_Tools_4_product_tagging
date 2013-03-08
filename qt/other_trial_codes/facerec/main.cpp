#include "facerec.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    facerec w;
    w.show();
    
    return a.exec();
}
