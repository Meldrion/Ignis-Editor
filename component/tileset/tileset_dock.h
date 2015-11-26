#ifndef TILESET_DOCK_H
#define TILESET_DOCK_H

#include <QDockWidget>
#include "component/tileset/tileset_tabber.h"

class Tileset_Dock : public QDockWidget
{
public:
    Tileset_Dock(QWidget* parent = 0);
    Tileset_Tabber* getTilesetTabber();
private:
    Tileset_Tabber* m_tileset_tabber;
};

#endif // TILESET_DOCK_H
