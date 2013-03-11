#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configureUI();
    path = "/home/rajeev/Dropbox/vios_team_use/face_recognition/videos/";
    videoFileName = path + "comcast_hd_small.avi";
    detectionFileName = path + "comcast_hd_small.dat";
    doneFlag = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configureUI(){
    signalMapper = new QSignalMapper(this);

    connect(ui->pushButtonConnect, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButtonConnect, QString::fromStdString("connect"));
    connect(ui->pushButtonPlay, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButtonPlay, QString::fromStdString("play"));
    connect(ui->pushButtonDisconnect, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButtonDisconnect, QString::fromStdString("disconnect"));
    connect(signalMapper, SIGNAL(mapped(const QString &)),this, SIGNAL(mapPushButtons(const QString &)));
    connect(this,SIGNAL(mapPushButtons(const QString &)),this,SLOT(decodePushButton(const QString &)));

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

void MainWindow::decodePushButton(const QString & pushButtonName){
    qDebug() << "decodePushButton : " << pushButtonName;
    if (pushButtonName == "connect"){
        qDebug() << "Connect Button Pressed";
        newClient = new NetzynClient();
        newClient->connectToServer(ui->lineEditHostAddress->text(),qint16(ui->lineEditPort->text().toInt()));
        ui->lineEditStatus->setText("Connected");
        ui->lineEditStatus->displayText();
    }
    else if (pushButtonName == "disconnect"){
        qDebug() << "Disconnect Button Pressed";
        newClient->disconnectFromServer();
        ui->lineEditStatus->setText("Disconnected");
        ui->lineEditStatus->displayText();
    }
    else if (pushButtonName == "play"){
        qDebug() << "Play Button Pressed";



        cap.open(videoFileName.c_str());
        numFrames = cap.get(CV_CAP_PROP_FRAME_COUNT);
        frameDelay = 1000/cap.get(CV_CAP_PROP_FPS);
        file.open(detectionFileName.c_str(),ifstream::in);
        if (!file){
            qDebug() << "Detections subfile not found";
        }
        else {
            overlayInfo.resize(numFrames);
            int ii = 0, numRect = 0;
            istringstream liness;
            string line;
            while (file.good()) {
                getline(file,line);
                liness.clear();
                liness.str(line);
                liness >> overlayInfo[ii].time >> numRect;
                overlayInfo[ii].box.resize(numRect);
                for (int jj =0; jj<numRect; jj++){
                    getline(file,line);
                    liness.clear();
                    liness.str(line);
                    liness >> overlayInfo[ii].box[jj].x >> overlayInfo[ii].box[jj].y >> overlayInfo[ii].box[jj].width >> overlayInfo[ii].box[jj].height;
                }
                ii++;
            }
        }
        // timing the overlay and display
        timerSceneUpdate = new QTimer(this);
        timerOverlayUpdate = new QTimer(this);
        connect(timerSceneUpdate, SIGNAL(timeout()), this, SLOT(updateScene()));
        connect(timerOverlayUpdate, SIGNAL(timeout()), this, SLOT(getOverlay()));
        timerOverlayUpdate->start(frameDelay);
        QTimer::singleShot(frameDelay - 3,this,SLOT(startSceneTimer()));
    }
}

void MainWindow::startSceneTimer(){
    qDebug() << "Entered startSceneTimer";
    timerSceneUpdate->start(frameDelay);
}

void MainWindow::updateScene(){
    scene->clear();
    Mat cvFrame;
    cap >> cvFrame;
    //cv::resize(cvFrame,cvFrame,Size(640,480));
    scene->clear();
    if (!cvFrame.empty()){
        frame = cvMatToQImage(cvFrame);
        if (ui->checkBoxDetect->isChecked())
            //scene->addPixmap(QPixmap::fromImage(newClient->overlayFrame));
            scene->addPixmap(QPixmap::fromImage(alphaBlend(frame,newClient->overlayFrame)));
        else
            scene->addPixmap(QPixmap::fromImage(frame));
    }
    else {
        doneFlag = 1;
    }
}

void MainWindow::getOverlay(){
    if (ui->checkBoxDetect->isChecked() && !doneFlag){
        QByteArray outData;
        QDataStream out(&outData,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        long long int curFramePos = cap.get(CV_CAP_PROP_POS_FRAMES) - 1;
        double horzResizeRatio=1, vertResizeRatio=1;
        //horzResizeRatio = 640/cap.get(CV_CAP_PROP_FRAME_WIDTH);
        //vertResizeRatio = 480/cap.get(CV_CAP_PROP_FRAME_HEIGHT);
        qDebug() << "Frame Size : " << cap.get(CV_CAP_PROP_FRAME_WIDTH) << cap.get(CV_CAP_PROP_FRAME_HEIGHT);
        qDebug() << "Resize Ratio : " << horzResizeRatio << vertResizeRatio;
        out << (qint64) overlayInfo[curFramePos].time << (qint16)overlayInfo[curFramePos].box.size();
        for (int ii=0; ii<overlayInfo[curFramePos].box.size(); ii++){
            out << (qint16)(overlayInfo[curFramePos].box[ii].x*horzResizeRatio) << (qint16)(overlayInfo[curFramePos].box[ii].y*vertResizeRatio) << (qint16)(overlayInfo[curFramePos].box[ii].width*horzResizeRatio) << (qint16)(overlayInfo[curFramePos].box[ii].height*vertResizeRatio);
        }
        newClient->socket->write(outData);
    }
}

// Convert OpenCV Mat to QImage format
QImage MainWindow::cvMatToQImage(const Mat& mat)
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

QImage MainWindow::alphaBlend(const QImage& baseImage, const QImage& overlayImage)
{
    QImage imageWithOverlay = QImage(baseImage.size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&imageWithOverlay);

    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(imageWithOverlay.rect(), Qt::transparent);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, baseImage);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, overlayImage);

    painter.end();

    return imageWithOverlay;
}

