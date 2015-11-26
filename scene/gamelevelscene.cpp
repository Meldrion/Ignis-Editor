#include "gamelevelscene.h"

GameLevelScene::GameLevelScene()
{
    this->m_game_level_unit_size = new QVector2D(0,0);


    // Dummy Code
    this->addLayer(new TilesetLayer());
    this->appendTileset(new Tileset("assets/images/desert.png",32));
}

GameLevelScene::~GameLevelScene()
{
    for (QVector<AbstractLayer*>::iterator it = this->m_layers.begin();it != this->m_layers.end();++it)
    {
        AbstractLayer* current = *it;
        delete current;
    }
}

int GameLevelScene::unit_width()
{
    return m_game_level_unit_size->x();
}

int GameLevelScene::unit_height()
{
    return m_game_level_unit_size->y();
}

int GameLevelScene::unit_value()
{
    return m_unit_size;
}

void GameLevelScene::setUnitSize(int unitSize)
{
    this->m_unit_size = unitSize;
}

void GameLevelScene::setGameLevelUnitDimension(int unit_width, int unit_height)
{
    this->m_game_level_unit_size->setX(unit_width);
    this->m_game_level_unit_size->setY(unit_height);
}

void GameLevelScene::addLayer(AbstractLayer *layer)
{
    if (TilesetLayer* ts_layer = dynamic_cast<TilesetLayer*>(layer))
    {
        if (this->m_tileset_catalog_listeners.contains(ts_layer))
            this->m_tileset_catalog_listeners.append(ts_layer);
    }

    this->m_layers.append(layer);
}

void GameLevelScene::paint(QPainter* graphics)
{
    int realWidth = m_game_level_unit_size->x() * m_unit_size;
    int realHeight = m_game_level_unit_size->y() * m_unit_size;

    graphics->fillRect(0,0,realWidth,realHeight,QBrush(QColor(255,255,255)));
}

void GameLevelScene::appendTileset(Tileset *tileset)
{
    if (!this->m_tilesets.contains(tileset))
    {
        this->m_tilesets.append(tileset);
        this->fireTilesetCatalogListeners();
    }
}

void GameLevelScene::removeTileset(int index)
{
    this->m_tilesets.remove(index);
    this->fireTilesetCatalogListeners();
}

QVector<Tileset*> GameLevelScene::getTilesets()
{
   return this->m_tilesets;
}

void GameLevelScene::fireTilesetCatalogListeners()
{
    for (QVector<Scene_Tileset_Catalog_Interface*>::iterator it = this->m_tileset_catalog_listeners.begin();
         it != this->m_tileset_catalog_listeners.end();++it)
    {
        Scene_Tileset_Catalog_Interface* stci = *it;
        stci->tileset_catalog_changed(&this->m_tilesets);
    }
}
