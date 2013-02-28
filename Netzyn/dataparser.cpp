#include "dataparser.h"

DataParser::DataParser()
{
}

void DataParser::getData(char * cdata){
    data = QString(cdata);
}

void DataParser::removeTerminators(){
    int n = data.size();
    int i;
    bool flag = FALSE;
    for (i=n-1; i>=0; i++){
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
    image.load((&buffer, "PNG");
}
