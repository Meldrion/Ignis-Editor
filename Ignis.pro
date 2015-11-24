#-------------------------------------------------
#
# Project created by QtCreator 2015-11-23T16:57:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ignis
TEMPLATE = app


SOURCES += main.cpp\
        ignismain.cpp \
    component/editorcanvas.cpp \
    scene/abstractscene.cpp \
    scene/gamelevelscene.cpp \
    scene/tilesetlayer.cpp \
    scene/abstractlayer.cpp \
    scene/tile.cpp \
    component/tilesetcanvas.cpp

HEADERS  += ignismain.h \
    component/editorcanvas.h \
    interface/activescenelistener.h \
    scene/abstractscene.h \
    scene/gamelevelscene.h \
    scene/tilesetlayer.h \
    scene/abstractlayer.h \
    scene/tile.h \
    component/tilesetcanvas.h

FORMS    += ignismain.ui
