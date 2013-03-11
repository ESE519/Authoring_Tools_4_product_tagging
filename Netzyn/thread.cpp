#include "thread.h"

Thread::Thread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void Thread::run()
{
    qDebug() << socketDescriptor << "Spawning new thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }
    in.setDevice(socket);
    in.setVersion(QDataStream::Qt_4_8);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << "Client Connected";
    exec();

}

void Thread::readyRead()
{
    qDebug() << socketDescriptor << socket->bytesAvailable() << " bytes available";
    QByteArray request,response,imgByteArray;
    QString inData;
    QDataStream out(&response,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    if (socket->bytesAvailable() >= 8){
        //request = socket->readAll();
        //qDebug() << socketDescriptor << "Data in : " << request.toHex();
        qint64 frameTime;
        qint16 numRect,x,y,width,height;
        in >> frameTime >> numRect;
        qDebug() << "frameTime : " << frameTime << "numRect : " << numRect;
        QPen qpen(QColor(255,0,0));
        // Read image;
        QImage img(QSize(640,480), QImage::Format_ARGB32_Premultiplied);  // Create the image with the exact size of the shrunk scene
        img.fill(Qt::transparent);
        QPainter painter;
        painter.begin(&img);
        painter.setPen(qpen); // use 1 to draw, the pen with is 1 pixel solid line
        for (int ii=0; ii<numRect; ii++){
            in >> x >> y >> width >> height;
            qDebug() << "Rectangle " << ii << " at : " << x << y << width << height;
            painter.drawRect(QRect(x,y,width,height));
        }
        //painter.fillRect(img.rect(), QColor(0, 0, 0, 0));
        painter.end();

        // Serialize Image
        QBuffer buffer(&imgByteArray);
        img.save(&buffer, "PNG");
        qDebug() << "Uncompressed Image size : " << imgByteArray.size();
        imgByteArray = qCompress(imgByteArray);
        //qDebug() << socketDescriptor << "Compressed Data : " << imgByteArray.toHex();

        // Write Data
        out << (qint64)imgByteArray.size();
        out << imgByteArray;
        socket->write(response);
        qDebug() << socketDescriptor << "Image compressed QByteArray Size : " << imgByteArray.size() << endl;
        qDebug() << socketDescriptor << "Data written" << response.size() << "bytes";
    }
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected: ";
    socket->deleteLater();
    exit(0);
}
