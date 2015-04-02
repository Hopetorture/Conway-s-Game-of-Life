#-------------------------------------------------
#
# Project created by QtCreator 2015-03-10T16:44:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = life-cells-visual
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    config.cpp \
    my_cell.cpp \

HEADERS  += mainwindow.h \
    config.h \
    my_cell.h \

FORMS    += mainwindow.ui
