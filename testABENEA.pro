#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T12:12:23
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testABENEA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    QRCodeGenerator.cpp



HEADERS  += mainwindow.h \
    QRCodeGenerator.h



FORMS    += mainwindow.ui

CONFIG += c++11

RESOURCES += \
    res.qrc


