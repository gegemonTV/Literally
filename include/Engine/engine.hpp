#pragma once

#include "Engine/Scene/scene.hpp"
#include "SDL.h"
#include "SDL_events.h"
class Scene;
class Engine {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Event event;

    Scene *currentScene;

    bool isPlaying = true;

    public:
        Engine(Scene *scene);
        ~Engine();

        int Run(int argc, char* argv[]);
        void PostScene(Scene *scene);
    
    private:
        int Init(int argc, char *argv[]);
        int Loop();
        int Clear();

        void EventReader();
        void Draw();

};