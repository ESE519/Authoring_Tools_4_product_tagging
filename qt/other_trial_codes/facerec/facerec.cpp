#include "facerec.h"
#include "ui_facerec.h"

facerec::facerec(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::facerec)
{
    ui->setupUi(this);
}

facerec::~facerec()
{
    delete ui;
}
