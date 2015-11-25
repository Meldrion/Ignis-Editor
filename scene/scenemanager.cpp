#include "scenemanager.h"

SceneManager::SceneManager()
{
    this->m_current_active_scene = 0x0;
}

void SceneManager::addActiveSceneListener(ActiveSceneListener *sceneListener)
{
    if (!this->m_active_scene_listeners.contains(sceneListener))
    {
        this->m_active_scene_listeners.append(sceneListener);
    }
}

void SceneManager::setActiveScene(AbstractScene *scene)
{
    this->m_current_active_scene = scene;
    for (QVector<ActiveSceneListener*>::iterator it = this->m_active_scene_listeners.begin();
         it != this->m_active_scene_listeners.end();++it)
    {
        ActiveSceneListener* asl = *it;
        asl->activeSceneChanged(scene);
    }
}
