#pragma once

#include "Engine/Object/gameobject.hpp"
#include <vector>
class Layer {
public:
    void Draw();
    void Update();
    void AddObject(GameObject *obj);

    std::vector<GameObject*> GetGameObjects();

private:
    std::vector<GameObject*> gameobjects = std::vector<GameObject*>();
};