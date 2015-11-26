#ifndef GAMELEVELSCENE_H
#define GAMELEVELSCENE_H

#include <QVector>
#include <QVector2D>
#include "interface/scene_tileset_catalog_interface.h"
#include "scene/abstractscene.h"
#include "scene/abstractlayer.h"
#include "scene/tilesetlayer.h"
#include "scene/tileset.h"

class GameLevelScene : public Abstract_Scene
{
    int m_unit_size;
    QVector2D* m_game_level_unit_size;
    QVector<AbstractLayer*> m_layers;
    QVector<Tileset*> m_tilesets;
    QVector<Scene_Tileset_Catalog_Interface*> m_tileset_catalog_listeners;
    void fireTilesetCatalogListeners();

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

    void appendTileset(Tileset* tileset);
    void removeTileset(int index);
    QVector<Tileset*> getTilesets();


signals:

public slots:
};

#endif // GAMELEVELSCENE_H
