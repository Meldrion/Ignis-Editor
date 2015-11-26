#include "tileset_dock.h"

Tileset_Dock::Tileset_Dock(QWidget* parent): QDockWidget(parent)
{
    this->setWindowTitle("Tileset Dock");
    this->m_tileset_tabber = new Tileset_Tabber(this);
    this->setWidget(this->m_tileset_tabber);
}

Tileset_Tabber* Tileset_Dock::getTilesetTabber()
{
    return this->m_tileset_tabber;
}
