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
#include "netzynclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QSignalMapper *signalMapper;
    NetzynClient *newClient;
    QImage img;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void configureUI();

signals:
    void mapPushButtons(const QString &);

private slots:
    void decodePushButton(const QString & pushButtonName);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
