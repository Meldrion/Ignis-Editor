#include "gamelevelscene.h"

GameLevelScene::GameLevelScene()
{
    this->m_game_level_unit_size = new QVector2D(0,0);
    this->m_layers.clear();

    // Dummy Code
    this->addLayer(new TilesetLayer());
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
    this->m_layers.append(layer);
}

void GameLevelScene::paint(QPainter* graphics)
{
    int realWidth = m_game_level_unit_size->x() * m_unit_size;
    int realHeight = m_game_level_unit_size->y() * m_unit_size;

    graphics->fillRect(0,0,realWidth,realHeight,QBrush(QColor(255,255,255)));
}
