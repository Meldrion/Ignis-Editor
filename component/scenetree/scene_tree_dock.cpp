#include "scene_tree_dock.h"

Scene_Tree_Dock::Scene_Tree_Dock(QWidget* parent) : QDockWidget(parent)
{
    setWindowTitle("SceneTree Dock");
    this->m_scene_tree = new Scene_Tree(this);
    this->setWidget(this->m_scene_tree);
}
