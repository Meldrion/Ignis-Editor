#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile();
    Tile(Tile* other);
    Tile(int sourceX,int sourceY,int destinationX,int destinationY);
    ~Tile();
    void set(int sourceX,int sourceY,int destinationX,int destinationY);
    int sourceX();
    int sourceY();
    int destinationX();
    int destinationY();
private:
    int m_source_x;
    int m_source_y;
    int m_destination_x;
    int m_destination_y;
};

#endif // TILE_H
