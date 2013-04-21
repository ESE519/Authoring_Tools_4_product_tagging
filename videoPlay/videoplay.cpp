#include "videoplay.h"
#include "ui_videoplay.h"

videoPlay::videoPlay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videoPlay)
{
    ui->setupUi(this);
    player=new Phonon::VideoPlayer;
    //QGraphicsScene scene;
    //QGraphicsProxyWidget *proxy = scene.addWidget(player);
    QString fileName("/home/shashidhar/Documents/RA/mclaren.avi");
    //Phonon::MediaSource media(QUrl("https://www.youtube.com/watch?v=PiPhg8kORoY"));
    Phonon::MediaSource media(fileName);
    //ui->graphicView->setScene(&scene);
    ui->verticalLayout->addWidget(player);
    QPainter paint;
    paint.begin(player);
    QPen pen1(QColor(255,0,0),3);
    paint.setPen(pen1);
    paint.drawRect(100,100,300,300);
    player->load(media);
    player->play(media);
    player->showFullScreen();

    m_pen = QPen(Qt::white,4);
    m_iOff = 0;
    m_iInc = 2;
    m_bPlus = true;

    QTimer *ptimer = new QTimer(this);
    connect( ptimer, SIGNAL( timeout()), this, SLOT (update() ) );
    ptimer->start(25);


    /*QWidget *widget = new QWidget;
    widget->setWindowTitle("Media Player");
    widget->resize(800,500);

    Phonon::MediaObject *media = new Phonon::MediaObject;
    media->setCurrentSource(Phonon::MediaSource("/home/shashidhar/Documents/RA/mclaren.avi"));

    Phonon::VideoWidget *vwidget = new Phonon::VideoWidget(widget);
    Phonon::createPath(media, vwidget);
    vwidget->setAspectRatio(Phonon::VideoWidget::AspectRatioAuto);
    Phonon::AudioOutput *aOutput = new Phonon::AudioOutput(Phonon::VideoCategory);
    Phonon::createPath(media, aOutput);
    vwidget->childAt(0,0);
    QLabel *label = new QLabel("Volume: ");
    Phonon::VolumeSlider *volumeSlider = new Phonon::VolumeSlider;
    volumeSlider->setAudioOutput(aOutput);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

   Phonon::SeekSlider *seekSlider = new Phonon::SeekSlider;
    seekSlider->setMediaObject(media);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(label);
    hLayout->addWidget(volumeSlider);
    hLayout->addStretch();

    QStackedLayout *videoStack = new QStackedLayout;
    myOverlay = new QWidget(vwidget);
    myOverlay->setFixedSize(900, 400);
    //myOverlay->setAttribute(Qt::WA_PaintOnScreen,TRUE);
    myOverlay->setAttribute(Qt::WA_TranslucentBackground);
    /*QGraphicsScene scene;
    scene.addRect(200,200,450,450,m_pen);
    QGraphicsView *view=new QGraphicsView(widget);
    view->setScene(&scene);
    QVBoxLayout *l_overlayLayout = new QVBoxLayout;
    l_overlayLayout->addWidget(label);
    myOverlay->setLayout(l_overlayLayout);
    videoStack->addWidget(vwidget);
    videoStack->addWidget(myOverlay);
    //videoStack->addWidget(view);
    videoStack->setStackingMode(QStackedLayout::StackAll);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(videoStack);
    vLayout->addWidget(seekSlider);
    vLayout->addLayout(hLayout);
    //ui->verticalLayout->addWidget(widget);
    widget->setLayout(vLayout);
    widget->showFullScreen();
    media->play();*/

}

videoPlay::~videoPlay()
{
    delete ui;
}

void videoPlay::paintEvent(QPaintEvent *event)
{
    Q_UNUSED( event );
    QPainter painter(this);

    // draw a rect
    painter.setPen( m_pen );
    int iHeight = size().height();
    int iWidth = size().width();
    painter.drawRect( m_iOff, m_iOff, iWidth/16, iHeight/16 );

    // move the rect for next time
    m_iOff = m_bPlus ? m_iOff + m_iInc : m_iOff - m_iInc;
    if ( (m_iOff < 0) | (iHeight/16 + m_iOff > iHeight) )
       m_bPlus = !m_bPlus;

}

// Called on left mouse event
void videoPlay::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED( event );
    m_pen = QPen(Qt::yellow,4);
    update();
}


// called for keypress
void videoPlay::keyPressEvent (QKeyEvent * event)
{
    int key = event->key();
    if ( key == '1' )
    {
        m_pen = QPen(Qt::red,4);
    }
    else if ( key == '2' )
    {
        m_pen = QPen(Qt::blue,4);
    }
    else if ( key == '+' )
    {
        m_iInc +=2;
    }
    else if ( key == '-' )
    {
        m_iInc -= 2;
    }
    update();

}
