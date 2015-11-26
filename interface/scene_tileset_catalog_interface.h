#ifndef SCENE_TILESET_CATALOG_INTERFACE
#define SCENE_TILESET_CATALOG_INTERFACE

#include <QVector>
#include "scene/tileset.h"

class Scene_Tileset_Catalog_Interface
{
public:
    virtual void tileset_catalog_changed(QVector<Tileset*> tileset_catalog) = 0;
};

#endif // SCENE_TILESET_CATALOG_INTERFACE

