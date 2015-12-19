#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "resource/scene/abstractscenelayer.h"
#include "resource/tileset.h"
#include <QDebug>
#include <QtMath>
#include <QWidget>
#include <QVector>
#include <QGraphicsSceneMouseEvent>
#include "rendering/tilerenderer.h"

namespace Ignis {
    class TileLayer : public AbstractSceneLayer
    {
        QVector<Tileset*> m_linked_tilesets;
        QVector<QVector<TileData* > > m_elements;
    public:
        TileLayer(int unit_width,int unit_height,int unit_size,QGraphicsItem* parent = 0);
        void init();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void addTileAt(int x,int y, int tilesetIndex,int tilesetX,int tilesetY);
        void deleteTileAt(int x,int y);
        void addTileset(Tileset* tileset);
    signals:

    public slots:
    };
}
#endif // GAMESCENE_H
