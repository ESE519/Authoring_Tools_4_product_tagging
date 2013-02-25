#-------------------------------------------------
#
# Project created by QtCreator 2013-02-25T15:00:07
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpServer
TEMPLATE = app


SOURCES += main.cpp\
        frame.cpp \
    server.cpp \
    thread.cpp

HEADERS  += frame.h \
    server.h \
    thread.h

FORMS    += frame.ui
