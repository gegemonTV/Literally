#include <iostream>
#include "Engine/Object/image.hpp"
#include "Engine/Scene/scene.hpp"
#include "Engine/engine.hpp"
#include "SDL_log.h"

using namespace std;

class FirstScene : public Scene {

    void OnCreate() override {
        std::cout<< "OnCreate" << std::endl;
        AddObject(0, new ImageObject(e->GetRenderer(), 0,0));
    }

    void OnUpdate() override {
        std::cout << "OnUpdate" << std::endl;
    }

    void OnDestroy() override {
        std::cout << "OnDestroy" << std::endl;
    }

    ~FirstScene() override {

    }
};

int main(int argc, char *argv[]) {
    cout << "Hi" << endl;

    Scene *sc = new FirstScene();
    
    Engine e = Engine();
    return e.Run(argc, argv, sc);
}