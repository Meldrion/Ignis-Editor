#include "editorcanvas.h"

EditorCanvas::EditorCanvas(QWidget *parent) : QWidget(parent)
{
    m_currentScene = 0x0;

    // Dummy Code

    GameLevelScene* tmp = new GameLevelScene();
    tmp->setGameLevelUnitDimension(50,50);
    tmp->setUnitSize(32);
    activeSceneChanged(tmp);

}

EditorCanvas::~EditorCanvas()
{
    delete m_currentScene;
}

void EditorCanvas::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QBrush(QColor(96,96,96)));

    if (m_currentScene)
    {
        m_currentScene->paint(&painter);
    }
}

void EditorCanvas::activeSceneChanged(AbstractScene *scene)
{
    if (scene)
    {
        GameLevelScene* gameLevelScene = dynamic_cast<GameLevelScene*>(scene);
        if (gameLevelScene)
        {
            int w = gameLevelScene->unit_width() * gameLevelScene->unit_value();
            int h = gameLevelScene->unit_height() * gameLevelScene->unit_value();
            setMinimumWidth(w);
            setMinimumHeight(h);
        }
            else
        {
            // Not a Game Level Scene
            setBaseSize(0,0);
        }
    }
        else
    {
        setBaseSize(0,0);
    }

    m_currentScene = scene;
    repaint();
}
