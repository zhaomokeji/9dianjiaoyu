#-------------------------------------------------
#
# Project created by QtCreator 2017-06-09T21:19:41
#
#-------------------------------------------------
CONFIG += qaxcontainer
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 9dianjiaoyu
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    model/qleftdirlistmodel.cpp \
    model/diritem.cpp \
    datasource/datasourcedirs.cpp

HEADERS  += mainwindow.h \
    qleftdirlistmodel.h \
    model/qleftdirlistmodel.h \
    model/diritem.h \
    datasource/datasourcedirs.h \
    common/datadefine.h

FORMS    += mainwindow.ui
