#include "tilesetlayer.h"

TilesetLayer::TilesetLayer(int unit_width,int unit_height)
{
    this->m_tiles_matrix = 0x0;
    this->setDimension(unit_width,unit_height);
}

void TilesetLayer::paint(QPainter* graphics)
{
    // Outer Loop
    for (QVector<QVector<Tile*>*>::iterator it = this->m_tiles_matrix->begin();
         it != this->m_tiles_matrix->end();++it)
    {
        // Inner Loop
        QVector<Tile*>* inner_tile_matrix = *it;
        for (QVector<Tile*>::iterator innerIt = inner_tile_matrix->begin();
             innerIt != inner_tile_matrix->end();++innerIt)
        {
            Tile* tile = *innerIt;
            if (tile)
            {
                // Get the tile and draw the tiles to the screen
                Tileset* tileset = this->m_tileset_catalog[tile->tilesetIndex()];

                // Draw the tiles to the screen
                tileset->drawTileTo(graphics,tile->sourceX(),tile->sourceY(),
                                    tile->destinationX(),tile->destinationY());
            }
        }
    }
}

void TilesetLayer::setDimension(int unitWidth, int unitHeight)
{
    this->m_unit_width = unitWidth;
    this->m_unit_height = unitHeight;
    this->m_tiles_matrix = buildTileMatrixFrom(m_tiles_matrix,unitWidth,unitHeight);
}

void TilesetLayer::tileset_catalog_changed(QVector<Tileset *> tileset_catalog)
{
    this->m_tileset_catalog = tileset_catalog;
}

void TilesetLayer::addTile(int sourceX,int sourceY,int destinationX,int destinationY,int tilesetIndex)
{
    // Get the current Tile at the given position
    Tile* tile = this->m_tiles_matrix->at(destinationX)->at(destinationY);
    // Check if the tile at the position is valid
    if (tile)
        // If so, just set the new details
        tile->set(sourceX,sourceY,destinationX,destinationY,tilesetIndex);
    else
        // Add a new Tile to the Index
        this->m_tiles_matrix->at(destinationX)
                ->replace(destinationY,new Tile(sourceX,sourceY,destinationX,destinationY,tilesetIndex));
}

void TilesetLayer::removeTile(int destinationX,int destinationY)
{
    delete this->m_tiles_matrix->at(destinationX)->at(destinationY);
    this->m_tiles_matrix->at(destinationX)->replace(destinationY,0x0);
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
