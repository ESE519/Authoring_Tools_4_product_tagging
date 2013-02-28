#-------------------------------------------------
#
# Project created by QtCreator 2013-02-27T22:29:49
#
#-------------------------------------------------

QT       += core
QT       += network

QT       += gui

TARGET = Netzyn
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    netzynserver.cpp \
    thread.cpp \
    dataparser.cpp

HEADERS += \
    netzynserver.h \
    thread.h \
    dataparser.h
