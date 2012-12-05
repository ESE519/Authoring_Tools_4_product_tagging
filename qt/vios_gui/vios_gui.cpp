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
    connect(ui->browse, SIGNAL(triggered(QAction*)), this, SLOT(changeDirectory()));
    fillList();
    Mat I = imread("../vios_gui/test.jpg");
    image = Mat2QImage(I);
    scene = new QGraphicsScene();
    ui->graphicsView_frame->setScene(scene);
    scene->addPixmap(QPixmap::fromImage(image));
}

ViosGui::~ViosGui()
{
    delete ui;
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


