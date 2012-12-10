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
    
public:
    int video_step, image_step, frame_pos,frame_count; //no of frame to be skipped
    Mat image_cv,selected_img;
    VideoCapture cap;
    QImage image_qt;
    QPixmap pixmap;
    QGraphicsScene *scene, *scene_detected, *scene_cropped;
    QGraphicsLineItem * hline, * vline1, * vline2;
    FaceRecognize recognizer;
    vector <Rect> face_pos;
    vector <struct Eye> eye;
    QPen default_pen, active_pen;
    QStringList image_filter,video_filter;
    QStringList image_names;
    string input_path,train_recognizer_file;
    int num_face_detections;
    bool video_mode_load_flag, image_mode_load_flag;
    explicit ViosGui(QWidget *parent = 0);
    ~ViosGui();
    QImage Mat2QImage(const Mat& mat);
    QString basestyle;
    vector <QString> style;
    vector <string> class_label;
    string class_label_file, train_path, junk_path, opencv_data_path;
    QRadioButton ** radio;
    QCheckBox ** check;
    int detection_strength;
    bool detection_flag, saved_flag;
    vector <Mat> train_img;
    vector <string> train_label;
    vector <int> train_num_label;
    ofstream ftrainwrite;

private:
    void update_image();
    void load_data();
    void custom_style_sheet();
    void train_gui(Mat & image_cv);

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

signals:
    void map_buttons(const QString &);

private:
    Ui::ViosGui *ui;
    QDir directory;
    QSignalMapper *signalMapper;
};

#endif // VIOS_GUI_H
