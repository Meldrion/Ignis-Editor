#ifndef SCENETREEDOCK_H
#define SCENETREEDOCK_H

#include <QDockWidget>
#include "component/scenetree/scene_tree.h"

class Scene_Tree_Dock : public QDockWidget
{
public:
    Scene_Tree_Dock(QWidget* parent = 0);
private:
    Scene_Tree* m_scene_tree;

public slots:
};

#endif // SCENETREEDOCK_H
