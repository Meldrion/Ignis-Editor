#include "scene_tree.h"

Scene_Tree::Scene_Tree(QWidget* parent) : QTreeWidget(parent)
{

}

QSize Scene_Tree::sizeHint() const
{
    return QSize(300,150);
}

