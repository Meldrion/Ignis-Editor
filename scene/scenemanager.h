#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QVector>
#include "interface/active_scene_listener.h"

class SceneManager
{
    QVector<Active_Scene_Listener*> m_active_scene_listeners;
    Abstract_Scene* m_current_active_scene;
public:
    SceneManager();
    void addActiveSceneListener(Active_Scene_Listener* sceneListener);
    void setActiveScene(Abstract_Scene* scene);

};

#endif // SCENEMANAGER_H
