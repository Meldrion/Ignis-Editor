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
    resource/scene/abstractscenelayer.cpp \
    resource/scene/tilelayer.cpp \
    resource/scene/scenebackgroundwhitelayer.cpp \
    resource/scene/mousecursorlayer.cpp \
    resource/scene/mousecursor.cpp \
    resource/scene/tiledata.cpp \
    resource/scene/scene.cpp \
    resource/tileset.cpp \
    rendering/tilerenderer.cpp \
    component/tileset/tileset_canvas.cpp \
    component/scenecanvas.cpp \
    component/tileset/tileset_dock.cpp \
    component/tileset/tileset_canvas_tab.cpp \
    component/tileset/tileset_tabber.cpp \
    component/scenetree/scene_tree.cpp \
    component/scenetree/scene_tree_dock.cpp

HEADERS  += gui/ignismain.h \
    resource/scene/abstractscenelayer.h \
    resource/scene/tilelayer.h \
    resource/scene/scenebackgroundwhitelayer.h \
    resource/scene/mousecursorlayer.h \
    resource/scene/mousecursor.h \
    resource/scene/tiledata.h \
    resource/scene/scene.h \
    resource/tileset.h \
    rendering/tilerenderer.h \
    component/tileset/tileset_canvas.h \
    component/scenecanvas.h \
    component/tileset/tileset_dock.h \
    component/tileset/tileset_canvas_tab.h \
    component/tileset/tileset_tabber.h \
    component/scenetree/scene_tree.h \
    component/scenetree/scene_tree_dock.h \

FORMS    += gui/ignismain.ui \

RESOURCES += \
    resource/icons.qrc
