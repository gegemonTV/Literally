#include "Engine/Scene/scene.hpp"
#include "Engine/Object/image.hpp"
#include "SDL_events.h"
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

void Scene::DispatchMouseEvents(int x, int y, SDL_Event event){
    CallObjectInArea(x, y, event);
}

void Scene::CallObjectInArea(int x, int y, SDL_Event event) {
    for (Layer l : layers) {
        for (auto i : l.GetGameObjects()) {
            if (i->IsInArea(x, y)) {
                i->CallOnMouseEvent(event);
            }
        }
    }
}

Scene::~Scene() {
}