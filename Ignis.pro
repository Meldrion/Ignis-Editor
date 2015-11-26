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
        gui/ignismain.cpp \
    scene/abstractscene.cpp \
    scene/gamelevelscene.cpp \
    scene/tilesetlayer.cpp \
    scene/abstractlayer.cpp \
    scene/tile.cpp \
    scene/tileset.cpp \
    scene/scenemanager.cpp \
    component/tileset/tileset_canvas.cpp \
    component/editor_canvas.cpp \
    component/tileset/tileset_dock.cpp \
    component/tileset/tileset_canvas_tab.cpp \
    component/tileset/tileset_tabber.cpp \
    component/scenetree/scene_tree.cpp \
    component/scenetree/scene_tree_dock.cpp

HEADERS  += gui/ignismain.h \
    scene/abstractscene.h \
    scene/gamelevelscene.h \
    scene/tilesetlayer.h \
    scene/abstractlayer.h \
    scene/tile.h \
    scene/tileset.h \
    scene/scenemanager.h \
    component/tileset/tileset_canvas.h \
    component/editor_canvas.h \
    component/tileset/tileset_dock.h \
    component/tileset/tileset_canvas_tab.h \
    component/tileset/tileset_tabber.h \
    interface/active_scene_listener.h \
    component/scenetree/scene_tree.h \
    component/scenetree/scene_tree_dock.h \
    interface/scene_tileset_catalog_interface.h

FORMS    += gui/ignismain.ui \

RESOURCES += \
    resource/icons.qrc
