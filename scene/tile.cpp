#include "tile.h"

Tile::Tile(int sourceX, int sourceY, int destinationX, int destinationY)
{
    set(sourceX,sourceY,destinationX,destinationY);
}

Tile::Tile(Tile *other)
{
    if (other)
    {
        set(other->sourceX(),other->sourceY(),other->destinationX(),other->destinationY());
    }
}

Tile::~Tile()
{

}

void Tile::set(int sourceX, int sourceY, int destinationX, int destinationY)
{
    this->m_source_x = sourceX;
    this->m_source_y = sourceY;
    this->m_destination_x = destinationX;
    this->m_destination_y = destinationY;
}

int Tile::sourceX()
{
    return this->m_source_x;
}

int Tile::sourceY()
{
    return this->m_source_y;
}

int Tile::destinationX()
{
    return this->m_destination_x;
}

int Tile::destinationY()
{
    return this->m_destination_y;
}
