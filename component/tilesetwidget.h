#ifndef TILESETWIDGET_H
#define TILESETWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "component/tilesetcanvas.h"

class TilesetWidget:public QScrollArea
{
public:
    TilesetWidget(Tileset* tileset,QWidget* parent = 0);
    ~TilesetWidget();
private:
    QVBoxLayout* m_layout;
    TilesetCanvas* m_tileset_canvas;
signals:

public slots:
};

#endif // TILESETWIDGET_H
