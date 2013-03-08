#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QString>
#include <QBuffer>
#include <QByteArray>
#include <QImage>
#include <QImageReader>

class DataParser
{
public:
    QString data;
    QByteArray byteData;
public:
    DataParser();
    DataParser(char * inputData);
    DataParser(QByteArray inputData);
    DataParser(QString inputData);
    void getData(char * inputData);
    void getData(QByteArray inputData);
    void getData(QString inputData);
    void serializeImage(QImage & image);
    void deserializeImage(QImage & image);
    void removeTerminator();
};

#endif // DATAPARSER_H
