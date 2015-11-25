#include "ignismain.h"
#include "ui_ignismain.h"

IgnisMain::IgnisMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IgnisMain)
{
    ui->setupUi(this);
    setWindowTitle("Ignis Studio");

    // Scene Manager
    this->m_sceneManager = new SceneManager();

    // Tileset Dock
    this->m_tilesetDock = new TilesetDock();

    // Create the EditorCanvas
    this->m_editorCanvas = new EditorCanvas(this->ui->scrollArea);
    this->ui->scrollArea->setWidget(this->m_editorCanvas);

    // Link the Active Scene Listeners and the Scene Manager
    this->m_sceneManager->addActiveSceneListener(this->m_editorCanvas);
    this->m_sceneManager->addActiveSceneListener(this->m_tilesetDock);

    // Add to the Dock
    this->addDockWidget(Qt::LeftDockWidgetArea,this->m_tilesetDock);

    // Center on Screen
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );


    // Dummy Code
    GameLevelScene* tmp = new GameLevelScene();
    tmp->setGameLevelUnitDimension(50,50);
    tmp->setUnitSize(32);
    this->m_sceneManager->setActiveScene(tmp);
}

IgnisMain::~IgnisMain()
{
    delete ui;
}
