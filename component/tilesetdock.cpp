#include "tilesetdock.h"
#include "ui_tilesetdock.h"

TilesetDock::TilesetDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::TilesetDock)
{
    ui->setupUi(this);
    this->m_tilesetCanvas = new TilesetCanvas(this->m_tilesetCanvas);
    this->ui->scrollArea->setWidget(this->m_tilesetCanvas);
}

TilesetDock::~TilesetDock()
{
    delete ui;
}

void TilesetDock::activeSceneChanged(AbstractScene *scene)
{
    GameLevelScene* game_level_scene = dynamic_cast<GameLevelScene*>(scene);
    if (game_level_scene)
    {
        QVector<Tileset*> tilesets = game_level_scene->getTilesets();
        for (QVector<Tileset*>::iterator it = tilesets.begin();it != tilesets.end();++it)
        {
            // Not the final code !
            this->m_tilesetCanvas->setTileset(*it);
        }

    }
}
