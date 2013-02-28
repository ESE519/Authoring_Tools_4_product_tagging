#-------------------------------------------------
#
# Project created by QtCreator 2013-02-28T02:25:48
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetzynClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dataparser.cpp \
    netzynclient.cpp

HEADERS  += mainwindow.h \
    dataparser.h \
    netzynclient.h

FORMS    += mainwindow.ui
