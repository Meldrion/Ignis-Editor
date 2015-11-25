#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QVector>
#include "interface/activescenelistener.h"

class SceneManager
{
    QVector<ActiveSceneListener*> m_active_scene_listeners;
    AbstractScene* m_current_active_scene;
public:
    SceneManager();
    void addActiveSceneListener(ActiveSceneListener* sceneListener);
    void setActiveScene(AbstractScene* scene);

};

#endif // SCENEMANAGER_H
