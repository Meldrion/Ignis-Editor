#ifndef TILESETLAYER_H
#define TILESETLAYER_H

#include "scene/abstractlayer.h"
#include "scene/tile.h"
#include <QVector>

class TilesetLayer : public AbstractLayer
{
public:
    TilesetLayer();
    void paint(QPainter *graphics);
    void setDimension(int unitWidth,int unitHeight);
private:
    int m_unit_width;
    int m_unit_height;
    QVector<QVector<Tile*>*>* m_tilesMatrix;
    QVector<QVector<Tile*>*>* buildEmptyTileMatrix(int unitWidth,int unitHeight);
    QVector<QVector<Tile*>*>* buildTileMatrixFrom(QVector<QVector<Tile*>*>* matrix,int unitWidth,int unitHeight);
    void deleteMatrix(QVector<QVector<Tile*>*>* matrix);
    bool isInRange(QVector<QVector<Tile*>*>* matrix,int x,int y);
signals:

public slots:
};

#endif // TILESETLAYER_H
