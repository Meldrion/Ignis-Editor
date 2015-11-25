#ifndef IGNISMAIN_H
#define IGNISMAIN_H

#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>
#include "component/editorcanvas.h"
#include "component/tilesetdock.h"
#include "scene/scenemanager.h"

namespace Ui {
class IgnisMain;
}

class IgnisMain : public QMainWindow
{
    Q_OBJECT
    SceneManager* m_sceneManager;
public:
    explicit IgnisMain(QWidget *parent = 0);
    ~IgnisMain();


private:
    Ui::IgnisMain *ui;
    EditorCanvas* m_editorCanvas;
    TilesetDock* m_tilesetDock;
};

#endif // IGNISMAIN_H
