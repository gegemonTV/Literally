#include "Engine/Scene/layer.hpp"
#include "Engine/Object/gameobject.hpp"

void Layer::AddObject(GameObject *obj) {
    gameobjects.push_back(obj);
}

void Layer::Draw() {
    for (GameObject* obj : gameobjects) {
        obj->Draw();
    }
}

void Layer::Update() {
    for (GameObject* obj : gameobjects) {
        obj->Update();
    }
}

std::vector<GameObject*> Layer::GetGameObjects(){
    return gameobjects;
}