#include "dataparser.h"

DataParser::DataParser()
{
}

DataParser::DataParser(char * inputData)
{
    data = QString(inputData);
    byteData = QByteArray(inputData);
}

DataParser::DataParser(QByteArray inputData)
{
    char * tmp = inputData.data();
    data = QString(tmp);
    byteData = inputData;
}

DataParser::DataParser(QString inputData)
{
    data = inputData;
    byteData = inputData.toAscii();
}

void DataParser::getData(char * inputData)
{
    data = QString(inputData);
    byteData = QByteArray(inputData);
}

void DataParser::getData(QByteArray inputData)
{
    char * tmp = inputData.data();
    data = QString(tmp);
    byteData = inputData;
}

void DataParser::getData(QString inputData)
{
    data = inputData;
    byteData = inputData.toAscii();
}

void DataParser::removeTerminator(){
    int n = data.size();
    int i;
    bool flag = FALSE;
    for (i=n-1; i>=0; i--){
        if (data[i] != '\r' && data[i] != '\n'){
            flag = TRUE;
            break;
        }
    }
    if (flag)
        data.resize(i+1);
    else
        data = "";
}

void DataParser::serializeImage(QImage & image){
    QBuffer buffer(&byteData);
    image.save(&buffer, "PNG");
    byteData = qCompress(byteData);
}

void DataParser::deserializeImage(QImage & image){
    byteData = qUncompress(byteData);
    QBuffer buffer(&byteData);
    image.load(&buffer, "PNG");
}
