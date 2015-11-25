#ifndef TILESETCANVAS_H
#define TILESETCANVAS_H

#include <QWidget>
#include <QPainter>
#include "scene/tileset.h"

class TilesetCanvas:public QWidget
{
    Q_OBJECT
public:
    explicit TilesetCanvas(QWidget* parent);
    void paintEvent(QPaintEvent *paintEvent);
    void setTileset(Tileset* tileset);
private:
    Tileset* m_tileset;
};

#endif // TILESETCANVAS_H
