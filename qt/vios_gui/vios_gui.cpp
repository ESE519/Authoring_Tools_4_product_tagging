#include "vios_gui.h"
#include "ui_vios_gui.h"
#include "general.h"

QImage ViosGui::Mat2QImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
} // MatToQImage()
ViosGui::ViosGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViosGui)
{
    ui->setupUi(this);
    video_step = 2*DEFAULT_VIDEO_STEP;
    signalMapper = new QSignalMapper(this);
    default_pen.setColor(QColor(255,0,0));
    default_pen.setJoinStyle(Qt::RoundJoin);
    active_pen.setColor(QColor(0,255,0));
    active_pen.setJoinStyle(Qt::RoundJoin);
    active_pen.setWidth(2);
    connect(ui->browse, SIGNAL(triggered(QAction*)), this, SLOT(change_directory()));

    connect(ui->fwd_skip_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->fwd_skip_button, QString::fromStdString("fwd_skip"));
    connect(ui->prev_skip_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->prev_skip_button, QString::fromStdString("prev_skip"));
    connect(ui->fwd_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->fwd_button, QString::fromStdString("fwd"));
    connect(ui->prev_button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->prev_button, QString::fromStdString("prev"));
    connect(signalMapper, SIGNAL(mapped(const QString &)),this, SIGNAL(map_buttons(const QString &)));
    connect(this,SIGNAL(map_buttons(const QString &)),this,SLOT(menu_decode(const QString &)));
    connect(ui->frame_skip_textedit, SIGNAL(textChanged()), this, SLOT(change_skip_step()));
    connect(ui->tmp_pushButton, SIGNAL(clicked()), this, SLOT(load_data()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()), this, SLOT(set_slider()));
    fill_list();
    scene = new QGraphicsScene();
    scene_detected = new QGraphicsScene();
    scene_cropped = new QGraphicsScene();
    ui->graphicsView_frame->setScene(scene);
    ui->graphicsView_detection->setScene(scene_detected);
    ui->graphicsView_processed->setScene(scene_cropped);
}

ViosGui::~ViosGui()
{
    delete ui;
}

void ViosGui::load_data()
{
    QString txt = ui->tmp_textEdit->toPlainText();
    string input_path = txt.toStdString();
    cap.open(input_path);
    frame_count = cap.get(CV_CAP_PROP_FRAME_COUNT);
    frame_pos = 0;
    ui->horizontalSlider->setMaximum(frame_count-1);
    ui->horizontalSlider->setTracking(1);
    update_image();
}

void ViosGui::menu_decode(const QString & button_name)
{
    int step = 0;
    if (button_name == "fwd_skip")
        step = video_step;
    else if (button_name == "prev_skip")
        step = -1* video_step;
    else if (button_name == "fwd")
        step = DEFAULT_VIDEO_STEP;
    else if (button_name == "prev")
        step = -1 * DEFAULT_VIDEO_STEP;
    frame_pos += step;
    update_image();
}

void ViosGui::update_image(void)
{
    if (frame_pos >= frame_count)
        frame_pos = frame_count - 1;
    else if (frame_pos < 0)
        frame_pos = 0;
    cap.set(CV_CAP_PROP_POS_FRAMES,frame_pos);
    cap >> image_cv;
    detector.detect_face(face_pos,eye,image_cv);
    frame_pos = cap.get(CV_CAP_PROP_POS_FRAMES);
    ui->horizontalSlider->setValue(frame_pos);
    image_qt = Mat2QImage(image_cv);
    scene->addPixmap(QPixmap::fromImage(image_qt));
    int num_detections = face_pos.size();
    if (num_detections > 0){
        scene->addRect(face_pos[0].x,face_pos[0].y,face_pos[0].width,face_pos[0].height,active_pen);
        scene_detected->clear();
        scene_detected->addPixmap(QPixmap::fromImage(Mat2QImage(image_cv(face_pos[0]))).scaled(150,150,Qt::IgnoreAspectRatio));
        for (int i=1;i<num_detections;i++)
            scene->addRect(face_pos[i].x,face_pos[i].y,face_pos[i].width,face_pos[i].height,default_pen);
    }
    else{
        scene_detected->clear();
        scene_cropped->clear();
    }
}

void ViosGui::set_slider()
{
    frame_pos = ui->horizontalSlider->value();
    QTextStream out(stdout);
    out << "\nValue :: " << frame_pos << "\n";
    update_image();
}

void ViosGui::change_skip_step()
{
    QString txt = ui->frame_skip_textedit->toPlainText();
    video_step = txt.toInt();
}

void ViosGui::change_directory()
{
/* select a directory using file dialog */
    QString path = QFileDialog::getExistingDirectory (this, tr("Directory"), directory.path());
    if ( path.isNull() == false )
    {
        directory.setPath(path);
        fill_list();
    }
}

/*get list of file from given directory and the append it to listWidget */
void ViosGui::fill_list()
{
    ui->listWidget->clear();
    ui->listWidget->addItems(directory.entryList());
}

