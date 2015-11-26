#ifndef TILESETWIDGET_H
#define TILESETWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "component/tileset/tileset_canvas.h"

class Tileset_Canvas_Tab:public QScrollArea
{
public:
    Tileset_Canvas_Tab(Tileset* tileset,QWidget* parent = 0);
    ~Tileset_Canvas_Tab();
private:
    QVBoxLayout* m_layout;
    Tileset_Canvas* m_tileset_canvas;
    QSize sizeHint() const;
signals:

public slots:
};

#endif // TILESETWIDGET_H
