#include "ignismain.h"
#include "ui_ignismain.h"

IgnisMain::IgnisMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IgnisMain)
{
    ui->setupUi(this);
    setWindowTitle("Ignis Studio");

    // Scene Manager
    //this->m_sceneManager = new SceneManager();

    // Tileset Dock
    this->m_tilesetDock = new Tileset_Dock(this);
    //this->m_sceneManager->addActiveSceneListener(this->m_tilesetDock->getTilesetTabber());

    // Scene tree Dock
    this->m_sceneTreeDock = new Scene_Tree_Dock(this);

    // Create the EditorCanvas
    this->m_sceneCanvas = new SceneCanvas(this->centralWidget());
    this->m_sceneCanvas->init();
    //this->ui->centralWidget->set
    //this->ui->scrollArea->setWidget(this->m_editorCanvas);

    // Link the Active Scene Listeners and the Scene Manager
    //this->m_sceneManager->addActiveSceneListener(this->m_editorCanvas);
    //this->m_sceneManager->addActiveSceneListener(this->m_tilesetDock);

    // Add to the Dock
    this->addDockWidget(Qt::LeftDockWidgetArea,this->m_tilesetDock);
    this->addDockWidget(Qt::LeftDockWidgetArea,this->m_sceneTreeDock);

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
    //this->m_sceneManager->setActiveScene(new GameLevelScene(30,30,32));
}

IgnisMain::~IgnisMain()
{
    delete ui;
}
