#include "Engine/Scene/scene.hpp"
#include "SDL_log.h"

Scene::Scene(){
    layers.push_back(Layer());
}

void Scene::AddObject(int layer, GameObject* obj) {
    if (layers.size() - 1 < layer) {
        SDL_LogError(0, "WTF DUDE, THERE IS NOT ENOUGH LAYERS!");
        return;
    }
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