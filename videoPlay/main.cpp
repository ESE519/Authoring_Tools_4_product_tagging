#include "videoplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    videoPlay w;
    w.QMainWindow::setWindowFlags(Qt::FramelessWindowHint);
    w.QMainWindow::setStyleSheet("background-color: transparent;");

    w.QMainWindow::showFullScreen();
    
    return a.exec();
}
