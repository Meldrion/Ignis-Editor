#include "tileset_canvas_tab.h"

Tileset_Canvas_Tab::Tileset_Canvas_Tab(Tileset* tileset,QWidget* parent):QScrollArea(parent)
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
    m_tileset_canvas = new Tileset_Canvas(this);

    // Link the Tileset to the Canvas
    m_tileset_canvas->setTileset(tileset);

    // Add the Canvas to the ScrollArea
    this->setWidget(m_tileset_canvas);
}

Tileset_Canvas_Tab::~Tileset_Canvas_Tab()
{
    delete m_layout;
    delete m_tileset_canvas;
}

QSize Tileset_Canvas_Tab::sizeHint() const
{
    return QSize(300,0);
}

