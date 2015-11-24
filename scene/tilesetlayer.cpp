#include "tilesetlayer.h"

TilesetLayer::TilesetLayer()
{
    m_tilesMatrix = 0x0;
    setDimension(20,15);
}

void TilesetLayer::paint(QPainter* graphics)
{

}

void TilesetLayer::setDimension(int unitWidth, int unitHeight)
{
    this->m_unit_width = unitWidth;
    this->m_unit_height = unitHeight;
    this->m_tilesMatrix = buildTileMatrixFrom(m_tilesMatrix,unitWidth,unitHeight);
}

QVector<QVector<Tile*>*>* TilesetLayer::buildEmptyTileMatrix(int unitWidth,int unitHeight)
{
    QVector<QVector<Tile*>*>* matrix = new QVector<QVector<Tile*>*>();
    for (int i=0;i<unitWidth;i++)
    {
        QVector<Tile*>* innerVector = new QVector<Tile*>();
        for (int j=0;j<unitHeight;j++)
        {
            innerVector->append(0x0);
        }

        matrix->append(innerVector);
    }

    return matrix;
}

QVector<QVector<Tile*>*>* TilesetLayer::buildTileMatrixFrom(QVector<QVector<Tile *> *> *matrix, int unitWidth, int unitHeight)
{
    if (matrix)
    {
        QVector<QVector<Tile*>*>* tmpMatrix = new QVector<QVector<Tile*>*>();
        for (int i=0;i<unitWidth;i++)
        {
            QVector<Tile*>* innerVector = new QVector<Tile*>();
            for (int j=0;j<unitHeight;j++)
            {
                if (isInRange(matrix,i,j))
                {
                    Tile* tile = new Tile(matrix->at(i)->at(j));
                    innerVector->append(tile);
                }
                    else
                {
                    innerVector->append(0x0);
                }
            }
            tmpMatrix->append(innerVector);

        }

        delete matrix;
        return tmpMatrix;
    }
        else
    {
        return buildEmptyTileMatrix(unitWidth,unitHeight);
    }
}

void TilesetLayer::deleteMatrix(QVector<QVector<Tile*>*>* matrix)
{
    for (QVector<QVector<Tile*>*>::iterator it = matrix->begin();it != matrix->end();++it)
    {

        QVector<Tile*>* innerVector = *it;
        for (QVector<Tile*>::iterator innerIt = innerVector->begin();innerIt != innerVector->end();++innerIt)
        {
            Tile* tile = *innerIt;
            delete tile;
        }

        delete innerVector;
    }
}

bool TilesetLayer::isInRange(QVector<QVector<Tile *> *> *matrix, int x, int y)
{
    return matrix && x < matrix->length() && y < matrix->at(0)->length();
}
