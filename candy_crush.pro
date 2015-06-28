#-------------------------------------------------
#
# Project created by QtCreator 2015-06-26T22:51:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candy_crush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    Destroy.cpp \
    Star.cpp \
    Vertical.cpp \
    Nineblock.cpp \
    Horizontal.cpp \
    Three.cpp

HEADERS  += mainwindow.h \
    blank.h \
    Destroy.h \
    Star.h \
    Vertical.h \
    Nineblock.h \
    Horizontal.h \
    Three.h

FORMS    += mainwindow.ui

RESOURCES += \
    candy.qrc
