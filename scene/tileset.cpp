#include "tileset.h"

Tileset::Tileset(QString imagePath, int tileSize)
{
    this->m_name = "Untitled";
    this->m_tileSize = tileSize;
    this->m_tilesetImage = new QImage();
    if (this->m_tilesetImage->load(imagePath))
    {
        this->m_image_unit_width = this->m_tilesetImage->width() / tileSize;
        this->m_image_unit_height = this->m_tilesetImage->height() / tileSize;
    }
        else
    {
        // Error
        this->m_image_unit_width = 0;
        this->m_image_unit_height = 0;
        qCritical() << "Could not load image " << imagePath;
    }
}

QString Tileset::getImagePath()
{
    return m_imagePath;
}

int Tileset::getTileSize()
{
    return this->m_tileSize;
}

int Tileset::getImageUnitWidth()
{
    return this->m_image_unit_width;
}

int Tileset::getImageUnitHeight()
{
    return this->m_image_unit_height;
}

QString Tileset::getName()
{
    return this->m_name;
}

void Tileset::drawTileTo(QPainter *graphics, int sourceX, int sourceY, int destinationX, int destinationY)
{
    graphics->drawImage(QRect(destinationX,destinationY,this->m_tileSize,this->m_tileSize),
                       *this->m_tilesetImage,
                       QRect(sourceX,sourceY,this->m_tileSize,this->m_tileSize));
}

void Tileset::draw(QPainter *graphics)
{
    graphics->drawImage(0,0,*this->m_tilesetImage);
}

