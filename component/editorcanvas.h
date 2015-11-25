#ifndef EDITORCANVAS_H
#define EDITORCANVAS_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include "interface/activescenelistener.h"
#include "scene/gamelevelscene.h"

class EditorCanvas : public QWidget , public ActiveSceneListener
{
    Q_OBJECT
private:
    AbstractScene* m_currentScene;
public:
    explicit EditorCanvas(QWidget *parent = 0);
    ~EditorCanvas();
    void paintEvent(QPaintEvent* paintEvent);
    void activeSceneChanged(AbstractScene *scene);
signals:

public slots:
};

#endif // EDITORCANVAS_H
