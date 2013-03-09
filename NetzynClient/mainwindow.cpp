#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configureUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configureUI(){
    signalMapper = new QSignalMapper(this);

    connect(ui->pushButtonConnect, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButtonConnect, QString::fromStdString("connect"));
    connect(ui->pushButtonSend, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButtonSend, QString::fromStdString("send"));
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
        connect(newClient,SIGNAL(updateScene()),this,SLOT(updateScene()));
        ui->lineEditStatus->setText("Connected");
        ui->lineEditStatus->displayText();
    }
    else if (pushButtonName == "disconnect"){
        qDebug() << "Disconnect Button Pressed";
        newClient->disconnectFromServer();
        ui->lineEditStatus->setText("Disconnected");
        ui->lineEditStatus->displayText();
    }
    else if (pushButtonName == "send"){
        qDebug() << "Send Button Pressed";
        QString tmp = "SEND";
        newClient->sendToServer(tmp);
        ui->lineEditStatus->setText("Sent");
        ui->lineEditStatus->displayText();
    }
}

void MainWindow::updateScene(){
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(newClient->frame));
}
