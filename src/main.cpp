#include <iostream>
#include <string>
#include "Engine/Object/Listener/MouseClickListener.hpp"
#include "Engine/Object/image.hpp"
#include "Engine/Scene/scene.hpp"
#include "Engine/UI/button.hpp"
#include "Engine/engine.hpp"
#include "Engine/UI/label.hpp"
#include "SDL_log.h"

class TestMouseListener : public MouseClickListener {
    void OnMouseDown() override {
        SDL_Log("Clicked");
    }

    void OnMouseReleased() override {
        //SDL_Log("Released");
    }

    void OnMouseUp() override {
        //SDL_Log("Up");
    }

    ~TestMouseListener() override {}
};

class FirstScene : public Scene {
    Label *l;
    Button *b;
    int c =0;
    void OnCreate() override {
        std::cout<< "OnCreate" << std::endl;
        ImageObject *obj = new ImageObject(e->GetRenderer(), "assets/images/zhabka.jpg", 50,50, 320, 240);

        l = new Label(e->GetRenderer(), "assets/fonts/font.ttf", "Hello", 100, 100);
        b = new Button(e->GetRenderer(), "Hello", "assets/images/kotik.jpg", 350, 350, 150, 50);
        b->SetOnMouseClickListener(new TestMouseListener());
        AddObject(0, obj);
        AddObject(0, l);
        AddObject(0, b);
    }

    void OnUpdate() override {
        //std::cout << "OnUpdate" << std::endl;
        c++;
        if (c%1000 == 0) {
            l->SetText(std::to_string(c));
        }
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