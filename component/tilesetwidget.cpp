#include "tilesetwidget.h"

TilesetWidget::TilesetWidget(Tileset* tileset,QWidget* parent):QScrollArea(parent)
{
    // Needed for the content to able to resize inside the scroll area
    this->setWidgetResizable(true);

    // Set the Layout
    m_layout = new QVBoxLayout(this);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);

    //Set a Layout for the ScrollArea
    this->setLayout(m_layout);

    // Create the TilesetCanvas
    m_tileset_canvas = new TilesetCanvas(this);

    // Link the Tileset to the Canvas
    m_tileset_canvas->setTileset(tileset);

    // Add the Canvas to the ScrollArea
    this->setWidget(m_tileset_canvas);
}

TilesetWidget::~TilesetWidget()
{
    delete m_layout;
    delete m_tileset_canvas;
}

