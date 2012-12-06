#-------------------------------------------------
#
# Project created by QtCreator 2012-12-04T13:04:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vios_gui
TEMPLATE = app

INCLUDEPATH += `pkg-config opencv --cflags`

LIBS += `pkg-config opencv --libs`

SOURCES += main.cpp\
        vios_gui.cpp \
    face.cpp

HEADERS  += vios_gui.h \
    general.h \
    face.h

FORMS    += vios_gui.ui
