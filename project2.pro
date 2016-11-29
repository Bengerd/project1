#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T19:14:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    screenwidget.cpp

HEADERS  += mainwindow.h \
    screenwidget.h\
    vertex.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
