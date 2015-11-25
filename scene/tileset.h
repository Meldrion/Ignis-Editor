#ifndef TILESET_H
#define TILESET_H

#include <QString>
#include <QImage>
#include <QPainter>
#include <QDebug>

class Tileset
{
public:
    Tileset(QString imagePath,int tileSize);
    QString getImagePath();
    int getTileSize();
    int getImageUnitWidth();
    int getImageUnitHeight();
    QString getName();
    void drawTileTo(QPainter* graphics,int sourceX,int sourceY,int destinationX,int destinationY);
    void draw(QPainter* graphics);
private:
    QImage* m_tilesetImage;
    QString m_imagePath;
    int m_image_unit_width;
    int m_image_unit_height;
    int m_tileSize;
    QString m_name;
signals:

public slots:
};

#endif // TILESET_H
