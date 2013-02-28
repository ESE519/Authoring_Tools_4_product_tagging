#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QString>
#include <QBuffer>
#include <QByteArray>
#include <QImage>

class DataParser
{
public:
    QString data;
    QByteArray byteData;
public:
    DataParser();
    void getData(char * cdata);
    void serializeImage(QImage & image);
    void deserializeImage(QImage & image);
    void removeTerminators();
};

#endif // DATAPARSER_H
