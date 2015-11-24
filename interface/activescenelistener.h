#ifndef ACTIVESCENELISTENER
#define ACTIVESCENELISTENER
#include "scene/abstractscene.h"

class ActiveSceneListener
{
    public:
        virtual void activeSceneChanged(AbstractScene* scene) = 0;
};

#endif // ACTIVESCENELISTENER

