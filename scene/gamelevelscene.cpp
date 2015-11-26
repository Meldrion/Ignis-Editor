#include "gamelevelscene.h"

GameLevelScene::GameLevelScene(int unit_width,int unit_height,int unit_size)
{
    this->m_game_level_unit_size = new QVector2D(0,0);

    this->setUnitSize(unit_size);
    this->setGameLevelUnitDimension(unit_width,unit_height);

    // Dummy Code
    this->appendTileset(new Tileset("assets/images/desert.png",32));

    TilesetLayer* ts_layer_1 = new TilesetLayer(unit_width,unit_height);
    this->addLayer(ts_layer_1);

    for (int i=0;i<50;i++)
    {
        for (int j=0;j<50;j++)
        {
            ts_layer_1->addTile(1,0,i,j,0);
        }
    }

    TilesetLayer* ts_layer_2 = new TilesetLayer(unit_width,unit_height);
    this->addLayer(ts_layer_2);
    for (int i=0;i<50;i++)
    {
        for (int j=0;j<50;j++)
        {
            ts_layer_2->addTile(0,2,i,j,0);
        }
    }

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
    // Check if the Layer is a a tileset tileset layer
    if (TilesetLayer* ts_layer = dynamic_cast<TilesetLayer*>(layer))
    {
        this->addTilesetCatalogListener(ts_layer);
    }

    // Only append the layer if it is valid and if it is not
    // allready included in the layer list
    if (layer && !this->m_layers.contains(layer))
        // Append the layer to the layer list
        this->m_layers.append(layer);
}

void GameLevelScene::paint(QPainter* graphics)
{
    int realWidth = m_game_level_unit_size->x() * m_unit_size;
    int realHeight = m_game_level_unit_size->y() * m_unit_size;

    graphics->fillRect(0,0,realWidth,realHeight,QBrush(QColor(255,255,255)));

    for (QVector<AbstractLayer*>::iterator it = this->m_layers.begin();
         it != this->m_layers.end();++it)
    {
        (*it)->paint(graphics);
    }
}

void GameLevelScene::addTilesetCatalogListener(Scene_Tileset_Catalog_Interface* listener)
{
    // Check if the layer is not allready a member of the listeners
    if (!this->m_tileset_catalog_listeners.contains(listener))
    {
        // Add the Layer to the Tileset Catalog change listeners
        this->m_tileset_catalog_listeners.append(listener);

        // Init the Tileset Layer
        listener->tileset_catalog_changed(this->m_tilesets);
    }
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
        stci->tileset_catalog_changed(this->m_tilesets);
    }
}
