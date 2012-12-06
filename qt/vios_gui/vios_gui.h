#ifndef VIOS_GUI_H
#define VIOS_GUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QImage>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QSignalMapper>
#include <QDir>
#include <QObject>
#include <QPen>
#include <QGraphicsRectItem>
#include <QList>
#include "general.h"
#include "face.h"

#define DEFAULT_VIDEO_STEP 10

using namespace face;

namespace Ui {
class ViosGui;
}

class ViosGui : public QMainWindow
{
    Q_OBJECT
    
public:
    int video_step, frame_pos,frame_count; //no of frame to be skipped
    Mat image_cv;
    VideoCapture cap;
    QImage image_qt;
    QPixmap pixmap;
    QGraphicsScene *scene, *scene_detected, *scene_cropped;
    FaceDetect detector;
    vector <Rect> face_pos;
    vector <struct Eye> eye;
    QPen default_pen, active_pen;
    explicit ViosGui(QWidget *parent = 0);
    ~ViosGui();
    QImage Mat2QImage(const Mat& mat);
    void update_image();

private slots:
    void change_directory();
    void fill_list();
    void load_data();
    void change_skip_step();
    void menu_decode(const QString &);
    void set_slider();

signals:
    void map_buttons(const QString &);

private:
    Ui::ViosGui *ui;
    QDir directory;
    QSignalMapper *signalMapper;
};

#endif // VIOS_GUI_H
