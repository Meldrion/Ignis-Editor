#ifndef ACTIVESCENELISTENER
#define ACTIVESCENELISTENER
#include "scene/abstractscene.h"

class Active_Scene_Listener
{
    public:
        virtual void activeSceneChanged(Abstract_Scene* scene) = 0;
};

#endif // ACTIVESCENELISTENER

