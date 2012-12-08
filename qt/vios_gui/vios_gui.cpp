#include "vios_gui.h"
#include "ui_vios_gui.h"
#include "general.h"
int bound (int x, int l, int u){
    if (x<l)
        x = l;
    else if (x>u)
        x = u;
    return x;
}

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

    directory = QDir::current();
    connect(ui->browse, SIGNAL(clicked()), this, SLOT(browse_files()));

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

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()), this, SLOT(set_slider()));

    connect(ui->show_margins, SIGNAL(clicked()), this, SLOT(show_margins()));

    connect(ui->h_indent, SIGNAL(valueChanged(double)), this, SLOT(change_margins(double)));
    connect(ui->v_indent, SIGNAL(valueChanged(double)), this, SLOT(change_margins(double)));

    scene = new QGraphicsScene();
    scene_detected = new QGraphicsScene();
    scene_cropped = new QGraphicsScene();
    ui->graphicsView_frame->setScene(scene);
    ui->graphicsView_detection->setScene(scene_detected);
    ui->graphicsView_processed->setScene(scene_cropped);
    vline1 = new QGraphicsLineItem();
    vline2 = new QGraphicsLineItem();
    hline = new QGraphicsLineItem();
    vline1->setPen(default_pen);
    vline2->setPen(default_pen);
    hline->setPen(default_pen);
}

ViosGui::~ViosGui()
{
    delete ui;
}

void ViosGui::load_data(string input_path)
{
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
    num_face_detections = face_pos.size();

    if (ui->show_margins->checkState()){
        scene_detected->removeItem(vline1);
        scene_detected->removeItem(vline2);
        scene_detected->removeItem(hline);
    }
    if (num_face_detections > 0){
        scene->addRect(face_pos[0].x,face_pos[0].y,face_pos[0].width,face_pos[0].height,active_pen);
        scene_detected->addPixmap(QPixmap::fromImage(Mat2QImage(image_cv(face_pos[0]))).scaled(150,150,Qt::IgnoreAspectRatio));
        //double scale = 150/face_pos[0].width;
        //if (eye[0].left_radius > 0)
        //    scene_detected->addEllipse(eye[0].left_pos.x*scale,eye[0].left_pos.y*scale,eye[0].left_radius*scale,eye[0].left_radius*scale,QPen(QColor(0,0,255)));
        //if (eye[0].right_radius > 0)
        //    scene_detected->addEllipse(eye[0].right_pos.x*scale,eye[0].right_pos.y*scale,eye[0].right_radius*scale,eye[0].right_radius*scale,QPen(QColor(0,0,255)));
        for (int i=1;i<num_face_detections;i++)
            scene->addRect(face_pos[i].x,face_pos[i].y,face_pos[i].width,face_pos[i].height,default_pen);
    }
    else{
        scene_cropped->clear();
    }
    if (ui->show_margins->checkState()){
        int x1 = ui->graphicsView_detection->geometry().width()*ui->h_indent->value();
        int y2 = ui->graphicsView_detection->geometry().height()-1;
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        y2 = bound(y2,1,ui->graphicsView_detection->geometry().height()-1);
        vline1->setLine(x1,1,x1,y2);
        x1 = ui->graphicsView_detection->geometry().width()*(1 - ui->h_indent->value());
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        vline2->setLine(x1,1,x1,y2);
        scene_detected->addItem(vline1);
        scene_detected->addItem(vline2);
        int y1 = ui->graphicsView_detection->geometry().height()*ui->v_indent->value();
        int x2 = ui->graphicsView_detection->geometry().width()-1;
        x2 = bound(x2,1,ui->graphicsView_detection->geometry().width()-1);
        y1 = bound(y1,1,ui->graphicsView_detection->geometry().height()-1);
        hline->setLine(1,y1,x2,y1);
        scene_detected->addItem(hline);
    }
}

void ViosGui::show_margins()
{
    if (ui->show_margins->checkState()){
        int x1 = ui->graphicsView_detection->geometry().width()*ui->h_indent->value();
        int y2 = ui->graphicsView_detection->geometry().height()-1;
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        y2 = bound(y2,1,ui->graphicsView_detection->geometry().height()-1);
        vline1->setLine(x1,1,x1,y2);
        x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
        x1 = ui->graphicsView_detection->geometry().width()*(1 - ui->h_indent->value());
        vline2->setLine(x1,1,x1,y2);
        scene_detected->addItem(vline1);
        scene_detected->addItem(vline2);
        int y1 = ui->graphicsView_detection->geometry().height()*ui->v_indent->value();
        int x2 = ui->graphicsView_detection->geometry().width()-1;
        x2 = bound(x2,1,ui->graphicsView_detection->geometry().width()-1);
        y1 = bound(y1,1,ui->graphicsView_detection->geometry().height()-1);
        hline->setLine(1,y1,x2,y1);
        scene_detected->addItem(hline);
    }
    else{
        scene_detected->removeItem(vline1);
        scene_detected->removeItem(vline2);
        scene_detected->removeItem(hline);
    }
}
void ViosGui::change_margins(double value)
{
    int x1 = ui->graphicsView_detection->geometry().width()*ui->h_indent->value();
    int y2 = ui->graphicsView_detection->geometry().height()-1;
    x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
    y2 = bound(y2,1,ui->graphicsView_detection->geometry().height()-1);
    vline1->setLine(x1,1,x1,y2);
    x1 = ui->graphicsView_detection->geometry().width()*(1 - ui->h_indent->value());
    x1 = bound(x1,1,ui->graphicsView_detection->geometry().width()-1);
    vline2->setLine(x1,1,x1,y2);
    int y1 = ui->graphicsView_detection->geometry().height()*ui->v_indent->value();
    int x2 = ui->graphicsView_detection->geometry().width()-1;
    y1 = bound(y1,1,ui->graphicsView_detection->geometry().height()-1);
    hline->setLine(1,y1,x2,y1);
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
void ViosGui::browse_files(){
 /* select a file using file dialog */
    QString path = QFileDialog::getOpenFileName(this, tr("Browse to add"), directory.path());
    if (path!=""){
        directory.setPath(path);
        load_data(path.toStdString());
    }
    ui->listWidget->clear();
    ui->listWidget->addItem(directory.absolutePath());
}
