#pragma once

#include "Engine/Object/gameobject.hpp"
#include "Engine/Scene/layer.hpp"
#include "Engine/engine.hpp"
#include "SDL_events.h"
#include "SDL_stdinc.h"
#include <vector>
class Engine;
class Scene {
    protected:
        Engine *e;
        std::vector<Layer> layers = std::vector<Layer>();

    public:
        Scene();
        void Draw();
        void Update();
        void AddObject(int layer, GameObject *obj);

        virtual void OnCreate() = 0;

        /**
        * Функция обновления сцены
        */
        virtual void OnUpdate() = 0;

        virtual void OnDestroy() = 0;
        virtual ~Scene();

        void SetEngine(Engine *engine);

        void DispatchMouseEvents(int x, int y, SDL_Event event);
    
    private:
        void CallObjectInArea(int x, int y, SDL_Event event);
        
};