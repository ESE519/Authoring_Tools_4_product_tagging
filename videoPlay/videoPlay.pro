#-------------------------------------------------
#
# Project created by QtCreator 2013-04-19T13:57:50
#
#-------------------------------------------------

QT       += core gui phonon Multimedia-lfl

QMAKE_CXXFLAGS += -I/usr/include/qt4/QtMultimediaKit -I/usr/include/qt4/QtMobility -lQtMultimediaKit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = videoPlay
TEMPLATE = app


SOURCES += main.cpp\
        videoplay.cpp

HEADERS  += videoplay.h

FORMS    += videoplay.ui
