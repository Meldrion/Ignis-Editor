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
    editorcanvas.cpp \
    scene/abstractscene.cpp \
    scene/gamelevelscene.cpp \
    scene/tilesetlayer.cpp \
    scene/abstractlayer.cpp \
    scene/tile.cpp

HEADERS  += ignismain.h \
    editorcanvas.h \
    interface/activescenelistener.h \
    scene/abstractscene.h \
    scene/gamelevelscene.h \
    scene/tilesetlayer.h \
    scene/abstractlayer.h \
    scene/tile.h

FORMS    += ignismain.ui
