#ifndef TILESETCANVAS_H
#define TILESETCANVAS_H

#include <QWidget>
#include <QPainter>
#include "resource/tileset.h"

class Tileset_Canvas:public QWidget
{
    Q_OBJECT
public:
    explicit Tileset_Canvas(QWidget* parent);
    void paintEvent(QPaintEvent *paintEvent);
    void setTileset(Tileset* tileset);
private:
    Tileset* m_tileset;
};

#endif // TILESETCANVAS_H
