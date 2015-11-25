#include "tilesetcanvas.h"

TilesetCanvas::TilesetCanvas(QWidget* parent = 0)
{
    this->m_tileset = 0x0;
}

void TilesetCanvas::paintEvent(QPaintEvent *paintEvent)
{
    QPainter graphics(this);
    graphics.fillRect(0,0,width(),height(),QBrush(QColor(96,96,96)));
    if (this->m_tileset)
    {
        this->m_tileset->draw(&graphics);
    }
}


void TilesetCanvas::setTileset(Tileset *tileset)
{
    this->m_tileset = tileset;
    if (tileset)
    {
        setMinimumWidth(tileset->getImageUnitWidth() * tileset->getTileSize());
        setMinimumHeight(tileset->getImageUnitHeight() * tileset->getTileSize());
    }
        else
    {
        setMinimumWidth(0);
        setMinimumHeight(0);
    }

    repaint();
}
