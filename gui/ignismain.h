#ifndef IGNISMAIN_H
#define IGNISMAIN_H

#include <QDebug>
#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>
#include <QShowEvent>
#include "component/scenecanvas.h"
#include "component/tileset/tileset_dock.h"
#include "component/scenetree/scene_tree_dock.h"

namespace Ui {
class IgnisMain;
}

class IgnisMain : public QMainWindow
{
    Q_OBJECT
    //SceneManager* m_sceneManager;

public:
    explicit IgnisMain(QWidget *parent = 0);
    ~IgnisMain();
private:
    Ui::IgnisMain *ui;
    //Scene
    Tileset_Dock* m_tilesetDock;
    Scene_Tree_Dock* m_sceneTreeDock;
    SceneCanvas* m_sceneCanvas;
};

#endif // IGNISMAIN_H
