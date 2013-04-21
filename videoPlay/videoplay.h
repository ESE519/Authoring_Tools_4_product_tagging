#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <phonon/VideoPlayer>
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/MediaSource>
#include <phonon/VideoWidget>
#include <phonon/VolumeSlider>
#include <phonon/SeekSlider>
#include <QLabel>
#include <QtMultimediaKit/QMediaPlayer>
#include <QStackedLayout>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QLibrary>
#include <QPainter>
#include <QPen>
#include <QColor>

namespace Ui {
class videoPlay;
}

class videoPlay : public QMainWindow
{
    Q_OBJECT
    Phonon::VideoPlayer *player;
    Phonon::VideoWidget *vidWid;

public:
    explicit videoPlay(QWidget *parent = 0);
    ~videoPlay();
    void keyPressEvent (QKeyEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::videoPlay *ui;
    QWidget *widget,*myOverlay;
    QPen m_pen;  // drawing color
    int m_iOff;  // offset from side
    bool m_bPlus; // if true inc offset, else dec offset
    int m_iInc;  // offset increment amount

};

#endif // VIDEOPLAY_H
