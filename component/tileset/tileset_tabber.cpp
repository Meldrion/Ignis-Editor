#include "tileset_tabber.h"

Tileset_Tabber::Tileset_Tabber(QWidget* parent) : QTabWidget(parent)
{

}

QSize Tileset_Tabber::sizeHint() const
{
    return QSize(300,350);
}

void Tileset_Tabber::activeSceneChanged(Abstract_Scene* scene)
{
    this->deleteAllocatedGUIComponents();
    GameLevelScene* game_level_scene = dynamic_cast<GameLevelScene*>(scene);
    if (game_level_scene)
    {
        QVector<Tileset*> tilesets = game_level_scene->getTilesets();
        for (QVector<Tileset*>::iterator it = tilesets.begin();it != tilesets.end();++it)
        {
            Tileset_Canvas_Tab* ts_tab = new Tileset_Canvas_Tab(*it,this);
            // Add the new Tileset Widget to the Tabber
            this->addTab(ts_tab,(*it)->getName());
            // Add the new Tileset Widget to the Vector with all the ts_widgets inside it
            this->m_tileset_tabs.append(ts_tab);
        }
    }
}

void Tileset_Tabber::deleteAllocatedGUIComponents()
{
    this->clear();
    // Delete all the Tileset Canvases that do still exists
    for (QVector<Tileset_Canvas_Tab*>::iterator it = this->m_tileset_tabs.begin();
         it != this->m_tileset_tabs.end();++it)
    {
        delete *it;
    }
}
