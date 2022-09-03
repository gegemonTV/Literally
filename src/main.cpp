#include <iostream>
#include "Engine/Scene/scene.hpp"
#include "Engine/engine.hpp"
#include "SDL_log.h"

using namespace std;

class FirstScene : public Scene {
    int counter = 0;
    void OnCreate() override {
        std::cout<<"OnCreate" << std::endl;
    }

    void OnUpdate() override {
        std::cout << "OnUpdate" << std::endl;
        counter++;
        if (counter%10 == 0) { 
            SDL_Log("1"); 
            e->PostScene(new FirstScene());
        }
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
    
    Engine e = Engine(sc);
    return e.Run(argc, argv);
}