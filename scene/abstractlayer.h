#ifndef ABSTRACTLAYER_H
#define ABSTRACTLAYER_H

#include <QPainter>

class AbstractLayer
{
public:
    AbstractLayer();
    virtual void paint(QPainter* graphics) = 0;
signals:

public slots:
};

#endif // ABSTRACTLAYER_H
