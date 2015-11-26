#ifndef EDITORCANVAS_H
#define EDITORCANVAS_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include "interface/active_scene_listener.h"
#include "scene/gamelevelscene.h"

class Editor_Canvas : public QWidget , public Active_Scene_Listener
{
    Q_OBJECT
private:
    Abstract_Scene* m_currentScene;
public:
    explicit Editor_Canvas(QWidget *parent = 0);
    ~Editor_Canvas();
    void paintEvent(QPaintEvent* paintEvent);
    void activeSceneChanged(Abstract_Scene *scene);
signals:

public slots:
};

#endif // EDITORCANVAS_H
