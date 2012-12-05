#include "vios_gui.h"
#include "ui_vios_gui.h"
QImage Mat2QImage(const Mat& mat)
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
    skip=1;
    connect(ui->browse, SIGNAL(triggered(QAction*)), this, SLOT(changeDirectory()));
    connect(ui->frame_fwd, SIGNAL(clicked()), this, SLOT(fwd_skip()));
    connect(ui->frame_prev, SIGNAL(clicked()), this, SLOT(prev_skip()));
    connect(ui->frame_skip, SIGNAL(textChanged()), this, SLOT(frame_no()));
    connect(ui->fwd, SIGNAL(clicked()), this, SLOT(one_fwd()));
    connect(ui->prev, SIGNAL(clicked()), this, SLOT(one_prev()));
    fillList();
    cap.open("/home/shashidhar/Downloads/bbts03e03.flv");
    max_frame = cap.get(CV_CAP_PROP_FRAME_COUNT);
    ImageUpdate();
    ui->horizontalSlider->setMaximum(max_frame-1);
}
void ViosGui::ImageUpdate()
{
    cap>>I;
    current_frame=cap.get(CV_CAP_PROP_POS_FRAMES);
    ui->horizontalSlider->setValue(current_frame);
    image = Mat2QImage(I);
    scene = new QGraphicsScene();
    ui->graphicsView_frame->setScene(scene);
    scene->addPixmap(QPixmap::fromImage(image));
}

ViosGui::~ViosGui()
{
    delete ui;
}

void ViosGui::one_fwd()
{
    cap.set(CV_CAP_PROP_POS_FRAMES,(current_frame+1));
    ImageUpdate();
}
void ViosGui::one_prev()
{
    cap.set(CV_CAP_PROP_POS_FRAMES,(current_frame-1));
    ImageUpdate();
}

void ViosGui::frame_no()
{
    QString txt = ui->frame_skip->toPlainText();
    skip = txt.toInt();
}

void ViosGui::fwd_skip()
{
    cap.set(CV_CAP_PROP_POS_FRAMES,(current_frame+skip));
    ImageUpdate();
}

void ViosGui::prev_skip()
{
    cap.set(CV_CAP_PROP_POS_FRAMES,(current_frame-skip));
    ImageUpdate();
}

void ViosGui::changeDirectory()
{
/* select a directory using file dialog */
    QString path = QFileDialog::getExistingDirectory (this, tr("Directory"), directory.path());
    if ( path.isNull() == false )
    {
        directory.setPath(path);
        fillList();
    }
}

/*get list of file from given directory and the append it to listWidget */
void ViosGui::fillList()
{
    ui->listWidget->clear();
    ui->listWidget->addItems(directory.entryList());
}
