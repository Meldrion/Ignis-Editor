#ifndef ABSTRACTSCENE_H
#define ABSTRACTSCENE_H

#include <QPainter>

class Abstract_Scene
{
public:
    Abstract_Scene();
    virtual void paint(QPainter* graphics) = 0;
signals:

public slots:
};

#endif // ABSTRACTSCENE_H
