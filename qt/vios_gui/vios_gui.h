#ifndef VIOS_GUI_H
#define VIOS_GUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QImage>
#include <QTextStream>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QDir>
#include <QObject>

using namespace std;
using namespace cv;

namespace Ui {
class ViosGui;
}

class ViosGui : public QMainWindow
{
    Q_OBJECT
    
public:
    int skip,current_frame,max_frame; //no of frame to be skipped
    Mat I;
    VideoCapture cap;
    QImage image;
    QPixmap pixmap;
    QGraphicsScene *scene;
    explicit ViosGui(QWidget *parent = 0);
    ~ViosGui();
    void add_frame(void);
    void ImageUpdate();

private slots:
    void changeDirectory();
    void fillList();
    void fwd_skip();
    void prev_skip();
    void frame_no();
    void one_fwd();
    void one_prev();

private:
    Ui::ViosGui *ui;
    QDir directory;
};

#endif // VIOS_GUI_H
