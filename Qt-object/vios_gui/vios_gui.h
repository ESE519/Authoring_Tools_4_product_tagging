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
#include <QDebug>
#include <QGraphicsRectItem>
#include <QList>
#include "general.h"
#include "face.h"
#include <QMouseEvent>

#define DEFAULT_VIDEO_STEP 10
#define X_offset 23
#define Y_offset 95
#define frame_width 645
#define frame_height 485

using namespace face;

namespace Ui {
class ViosGui;
}

class ViosGui : public QMainWindow
{
    Q_OBJECT
    
public:
    int video_step, image_step, frame_pos,frame_count,mouse_act,image_select_flag; //no of frame to be skipped
    bool mouseclick,update_flag;
    Mat image_cv,selected_image;
    Rect detect;
    VideoCapture cap;
    QImage image_qt,select_qimage;
    QPoint initial,last,current,previous_point;
    QPixmap pixmap,mouse_detect;
    QGraphicsScene *scene, *scene_detected, *scene_cropped,*obj_scene,*scene_obj_selected;
    QGraphicsLineItem * hline, * vline1, * vline2;
    QGraphicsRectItem *obj_rect;
    FaceDetect detector;
    vector <Rect> face_pos;
    vector <struct Eye> eye;
    QPen default_pen, active_pen;
    QStringList image_filter;
    QStringList image_names;
    string input_path;
    int num_face_detections;
    explicit ViosGui(QWidget *parent = 0);
    ~ViosGui();
    QImage Mat2QImage(const Mat& mat);

private:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void update_image();
    void load_data();

private slots:
    void browse_files();
    void change_skip_step();
    void menu_decode(const QString &);
    void set_slider();
    void show_margins();
    void change_margins(double);

signals:
    void map_buttons(const QString &);
    void obj_map_buttons(const QString &);
    void mouseClickEvent();

private:
    Ui::ViosGui *ui;
    QDir directory;
    QSignalMapper *signalMapper,*signalMapper_obj;
};

#endif // VIOS_GUI_H
