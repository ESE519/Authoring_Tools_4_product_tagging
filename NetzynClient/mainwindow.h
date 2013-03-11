#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QImage>
#include <QTextStream>
#include <QDebug>
#include <QSignalMapper>
#include <QDir>
#include <QObject>
#include <QPen>
#include <QGraphicsRectItem>
#include <QList>
#include <QRadioButton>
#include <QCheckBox>
#include <QGraphicsScene>
#include <QTimer>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "netzynclient.h"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QSignalMapper *signalMapper;
    NetzynClient *newClient;
    QImage frame;
    QTimer *timerSceneUpdate, *timerOverlayUpdate;
    VideoCapture cap;
    ifstream file;
    int numFrames, frameDelay;
    string videoFileName, detectionFileName,path;
    struct Box{
        int x,y,width,height;
    };

    struct overlay{
        long long int time;
        vector <struct Box> box;
    };
    vector <struct overlay> overlayInfo;
    bool doneFlag;

public:
    QGraphicsScene *scene;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void configureUI();
    QImage cvMatToQImage(const Mat& mat);
    QImage alphaBlend(const QImage & baseImage, const QImage & overlayImage);

signals:
    void mapPushButtons(const QString &);

private slots:
    void decodePushButton(const QString & pushButtonName);
    void updateScene();
    void getOverlay();
    void startSceneTimer();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
