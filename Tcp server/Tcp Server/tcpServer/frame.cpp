#include "frame.h"
#include "ui_frame.h"

frame::frame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frame)
{
    ui->setupUi(this);
}

frame::~frame()
{
    delete ui;
}
