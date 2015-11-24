#ifndef GAMELEVELSCENE_H
#define GAMELEVELSCENE_H

#include <QVector>
#include <QVector2D>
#include "scene/abstractscene.h"
#include "scene/abstractlayer.h"
#include "scene/tilesetlayer.h"

class GameLevelScene : public AbstractScene
{
    int m_unit_size;
    QVector2D* m_game_level_unit_size;
    QVector<AbstractLayer*> m_layers;

public:
    GameLevelScene();
    ~GameLevelScene();
    int unit_width();
    int unit_height();
    int unit_value();
    void setUnitSize(int unitSize);
    void setGameLevelUnitDimension(int unit_width,int  unit_height);
    void addLayer(AbstractLayer* layer);
    void paint(QPainter* graphics);

signals:

public slots:
};

#endif // GAMELEVELSCENE_H
