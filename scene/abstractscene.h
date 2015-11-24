#ifndef ABSTRACTSCENE_H
#define ABSTRACTSCENE_H

#include <QPainter>

class AbstractScene
{
public:
    AbstractScene();
    virtual void paint(QPainter* graphics) = 0;
signals:

public slots:
};

#endif // ABSTRACTSCENE_H
