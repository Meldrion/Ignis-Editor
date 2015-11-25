#ifndef TILESETDOCK_H
#define TILESETDOCK_H

#include <QDockWidget>
#include "component/tilesetcanvas.h"
#include "interface/activescenelistener.h"
#include "scene/gamelevelscene.h"

namespace Ui {
class TilesetDock;
}

class TilesetDock : public QDockWidget , public ActiveSceneListener
{
    Q_OBJECT

public:
    explicit TilesetDock(QWidget *parent = 0);
    ~TilesetDock();
    void activeSceneChanged(AbstractScene *scene);

private:
    Ui::TilesetDock *ui;
    TilesetCanvas* m_tilesetCanvas;
};

#endif // TILESETDOCK_H
