#pragma once

#include "Engine/Object/gameobject.hpp"
#include "Engine/Scene/layer.hpp"
#include "Engine/engine.hpp"
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
    
    private:
        
};