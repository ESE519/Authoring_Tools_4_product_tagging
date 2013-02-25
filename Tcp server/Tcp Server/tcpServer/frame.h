#ifndef FRAME_H
#define FRAME_H

#include <QMainWindow>

namespace Ui {
class frame;
}

class frame : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit frame(QWidget *parent = 0);
    ~frame();
    
private:
    Ui::frame *ui;
};

#endif // FRAME_H
