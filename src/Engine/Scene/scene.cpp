#include "Engine/Scene/scene.hpp"

void Scene::AddObject(int layer, GameObject* obj) {
    layers.at(layer).AddObject(obj);
}

void Scene::Draw() {
    for (auto layer : layers) {
        layer.Draw();
    }
}

void Scene::Update() {
    OnUpdate();
    for (auto layer : layers) {
        layer.Update();
    }
}

void Scene::SetEngine(Engine *engine){
    e = engine;
}

Scene::~Scene() {
}