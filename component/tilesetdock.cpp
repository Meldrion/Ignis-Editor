#include "tilesetdock.h"
#include "ui_tilesetdock.h"

TilesetDock::TilesetDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::TilesetDock)
{
    ui->setupUi(this);
}

TilesetDock::~TilesetDock()
{
    deleteAllocatedGUIComponents();
    delete ui;
}

void TilesetDock::activeSceneChanged(AbstractScene *scene)
{
    deleteAllocatedGUIComponents();
    GameLevelScene* game_level_scene = dynamic_cast<GameLevelScene*>(scene);
    if (game_level_scene)
    {
        QVector<Tileset*> tilesets = game_level_scene->getTilesets();
        for (QVector<Tileset*>::iterator it = tilesets.begin();it != tilesets.end();++it)
        {
            TilesetWidget* ts_widget = new TilesetWidget(*it,this->ui->tilesetTabber);
            // Add the new Tileset Widget to the Tabber
            this->ui->tilesetTabber->addTab(ts_widget,(*it)->getName());
            // Add the new Tileset Widget to the Vector with all the ts_widgets inside it
            this->m_tilesetWidgets.append(ts_widget);
        }
    }
}

void TilesetDock::deleteAllocatedGUIComponents()
{
    this->ui->tilesetTabber->clear();
    // Delete all the Tileset Canvases that do still exists
    for (QVector<TilesetWidget*>::iterator it = this->m_tilesetWidgets.begin();
         it != this->m_tilesetWidgets.end();++it)
    {
        delete *it;
    }
}
