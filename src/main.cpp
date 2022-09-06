#include <iostream>
#include "Engine/Object/Listener/MouseClickListener.hpp"
#include "Engine/Object/image.hpp"
#include "Engine/Scene/scene.hpp"
#include "Engine/engine.hpp"
#include "SDL_log.h"

class TestMouseListener : public MouseClickListener {
    void OnMouseDown() override {
        SDL_Log("Down");
    }

    void OnMouseReleased() override {
        SDL_Log("Released");
    }

    void OnMouseUp() override {
        SDL_Log("Up");
    }

    ~TestMouseListener() override {}
};

class FirstScene : public Scene {

    void OnCreate() override {
        std::cout<< "OnCreate" << std::endl;
        ImageObject *obj = new ImageObject(e->GetRenderer(), "assets/images/zhabka.jpg", 0,0, 640, 480);
        obj->SetOnMouseClickListener(new TestMouseListener());
        AddObject(0, obj);
    }

    void OnUpdate() override {
        //std::cout << "OnUpdate" << std::endl;
    }

    void OnDestroy() override {
        std::cout << "OnDestroy" << std::endl;
    }

    ~FirstScene() override {

    }
};

int main(int argc, char *argv[]) {

    Scene *sc = new FirstScene();
    
    Engine e = Engine();
    return e.Run(argc, argv, sc);
}