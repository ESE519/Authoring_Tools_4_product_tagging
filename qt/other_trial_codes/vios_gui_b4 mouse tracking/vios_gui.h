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
#include <QRadioButton>
#include <QCheckBox>

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
// Member Variables
public:
    // C++ datatype members
    int video_step, image_step, frame_pos,frame_count, num_face_detections, detection_strength;
    bool video_mode_load_flag, image_mode_load_flag, obj_image_load_flag, obj_video_load_flag, detection_flag, saved_flag;
    string input_path, train_recognizer_file, class_label_file, train_path, junk_path, opencv_data_path;
    vector <int> train_num_label;
    vector <string> class_label, train_label;
    ofstream ftrainwrite;

    // OpenCV datatype members
    Mat image_cv,selected_img;
    VideoCapture cap;
    FaceRecognize recognizer;
    vector <Mat> train_img;
    vector <Rect> face_pos;
    vector <struct Eye> eye;

    // QT datatype members
    QImage image_qt;
    QPixmap pixmap;
    QGraphicsScene *scene, *scene_detected, *scene_cropped,*scene_obj,*scene_cropped_obj;
    QGraphicsLineItem * hline, * vline1, * vline2;
    QPen default_pen, active_pen;
    QStringList image_filter,video_filter;
    QStringList image_names;
    QString basestyle;
    vector <QString> style;
    QRadioButton ** radio;
    QCheckBox ** check;

private:
    Ui::ViosGui *ui;
    QDir directory;
    QSignalMapper *signalMapper;

// Member Functions
public:
    explicit ViosGui(QWidget *parent = 0);
    ~ViosGui();
    QImage Mat2QImage(const Mat& mat);

private:
    void obj_img_update();
    void update_image();
    void load_data();
    void custom_style_sheet();
    void train_gui(Mat & image_cv);

// Signals and slots
signals:
    void map_buttons(const QString &);

private slots:
    void browse_files();
    void change_skip_step();
    void menu_decode(const QString &);
    void set_slider();
    void show_margins();
    void change_margins(double);
    void delete_labels();
    void add_labels();
    void select_image();
    void discard_image();
    void build_recognizer();
};

#endif // VIOS_GUI_H
