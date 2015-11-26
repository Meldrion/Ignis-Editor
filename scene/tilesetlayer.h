#ifndef TILESETLAYER_H
#define TILESETLAYER_H

#include "interface/scene_tileset_catalog_interface.h"
#include "scene/abstractlayer.h"
#include "scene/tile.h"
#include <QVector>

class TilesetLayer : public AbstractLayer , public Scene_Tileset_Catalog_Interface
{
public:
    TilesetLayer(int unit_width,int unit_height);
    void paint(QPainter *graphics);
    void setDimension(int unitWidth,int unitHeight);
    void tileset_catalog_changed(QVector<Tileset *> tileset_catalog);
    void addTile(int sourceX,int sourceY,int destinationX,int destinationY,int tilesetIndex);
    void removeTile(int destinationX,int destinationY);
private:
    int m_unit_width;
    int m_unit_height;
    QVector<Tileset*> m_tileset_catalog;
    QVector<QVector<Tile*>*>* m_tiles_matrix;
    QVector<QVector<Tile*>*>* buildEmptyTileMatrix(int unitWidth,int unitHeight);
    QVector<QVector<Tile*>*>* buildTileMatrixFrom(QVector<QVector<Tile*>*>* matrix,int unitWidth,int unitHeight);
    void deleteMatrix(QVector<QVector<Tile*>*>* matrix);
    bool isInRange(QVector<QVector<Tile*>*>* matrix,int x,int y);
signals:

public slots:
};

#endif // TILESETLAYER_H
