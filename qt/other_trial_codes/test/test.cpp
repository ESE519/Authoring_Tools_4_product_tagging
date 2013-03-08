#include <QTextStream>
#include <QDebug>
#include <QImageReader>
#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QImage>
int main(int argc, char *argv[])
{
QApplication a(argc, argv);
QImage I;
I.load("../vios_gui/test.jpg");
QTextStream out(stdout);
out << "image size :" << I.width();
QGraphicsView* w = new QGraphicsView();
QGraphicsScene *scn = new QGraphicsScene();
//scn->setSceneRect( w->rect() );
w->setScene( scn );
//w->setFixedSize( 400, 400 );
QPixmap pix=QPixmap::fromImage(I);
scn->addPixmap( pix );
w->show();
return a.exec();
}
