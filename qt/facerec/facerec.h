#ifndef FACEREC_H
#define FACEREC_H

#include <QMainWindow>

namespace Ui {
class facerec;
}

class facerec : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit facerec(QWidget *parent = 0);
    ~facerec();
    
private:
    Ui::facerec *ui;
};

#endif // FACEREC_H
