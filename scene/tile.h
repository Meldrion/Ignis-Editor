#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile();
    Tile(Tile* other);
    Tile(int sourceX,int sourceY,int destinationX,int destinationY,int tilesetIndex);
    ~Tile();
    void set(int sourceX,int sourceY,int destinationX,int destinationY,int tilesetIndex);
    int sourceX();
    int sourceY();
    int destinationX();
    int destinationY();
    int tilesetIndex();
private:
    int m_source_x;
    int m_source_y;
    int m_destination_x;
    int m_destination_y;
    int m_tileset_index;
};

#endif // TILE_H
