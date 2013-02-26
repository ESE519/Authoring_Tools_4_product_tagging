#include <QApplication>
#include <QWidget>
#include <QPen>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QLibrary>

//
// Simple widget that draw's itself
// moves a small rectangle across the screen
//
class NzWidget : public QWidget
{
  Q_OBJECT
  public:
    NzWidget(QWidget * parent = 0)
    {
        Q_UNUSED( parent );
  
        // save initial rect values
        m_pen = QPen(Qt::white,4);
        m_iOff = 0;
        m_iInc = 2;
        m_bPlus = true;

        // create a timer that calls Qt update() every 40ms
        // update() will call paintEvent()
        QTimer *ptimer = new QTimer(this);
        connect( ptimer, SIGNAL( timeout()), this, SLOT (update() ) );
        ptimer->start(25);
    }
    ~NzWidget()
    {
    }

  protected:

    // called for every paint
    // must completely redraw everything
    void paintEvent(QPaintEvent *event)
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
    void mousePressEvent(QMouseEvent *event)
    {
        Q_UNUSED( event );
        m_pen = QPen(Qt::yellow,4);
        update();
    }


    // called for keypress
    void keyPressEvent (QKeyEvent * event)
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

  private:
    QPen m_pen;  // drawing color
    int m_iOff;  // offset from side
    bool m_bPlus; // if true inc offset, else dec offset
    int m_iInc;  // offset increment amount

};


#include "NzQtInterface.h"

int main(int argc, char *argv[])
{
    QLibrary nzqt("libnzqt");
    // COMMENT OUT to test without NzOS
    // Initialize NzOS
    //NzQtInterface::QTInit(argc, argv);

    // Initialize Qt
    QApplication app(argc, argv);

    // Create a single widget that has no frame, is transparent 
    NzWidget widget;
    widget.setWindowFlags(Qt::FramelessWindowHint);
    widget.setStyleSheet("background-color: transparent;");

    // COMMENT OUT to test without NzOS
    // Set widget size to full screen
   // widget.resize(NzQtInterface::getWidth(), NzQtInterface::getHeight());



    // Show the weidget and run Qt
    widget.show();
    return app.exec();
}

// needed for SINGLE/SLOTS because NzWidget is not declared in a .h file
#include "widget.moc"
