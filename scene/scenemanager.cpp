#include "scenemanager.h"

SceneManager::SceneManager()
{
    this->m_current_active_scene = 0x0;
}

void SceneManager::addActiveSceneListener(Active_Scene_Listener *sceneListener)
{
    if (!this->m_active_scene_listeners.contains(sceneListener))
    {
        this->m_active_scene_listeners.append(sceneListener);
    }
}

void SceneManager::setActiveScene(Abstract_Scene *scene)
{
    this->m_current_active_scene = scene;
    for (QVector<Active_Scene_Listener*>::iterator it = this->m_active_scene_listeners.begin();
         it != this->m_active_scene_listeners.end();++it)
    {
        Active_Scene_Listener* asl = *it;
        asl->activeSceneChanged(scene);
    }
}
