#ifndef TILESET_TABBER_H
#define TILESET_TABBER_H

#include <QTabWidget>
#include <QVector>
//#include "interface/active_scene_listener.h"
//#include "scene/gamelevelscene.h"
#include "component/tileset/tileset_canvas_tab.h"

class Tileset_Tabber : public QTabWidget
{
public:
    Tileset_Tabber(QWidget* parent = 0);
    //void activeSceneChanged(Abstract_Scene *scene);
    QSize sizeHint() const;
private:
    void deleteAllocatedGUIComponents();
    QVector<Tileset_Canvas_Tab*> m_tileset_tabs;
signals:

public slots:
};

#endif // TILESET_TABBER_H
