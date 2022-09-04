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

    Scene *currentScene = NULL;

    bool isPlaying = true;

    public:
        ~Engine();

        int Run(int argc, char* argv[], Scene *firstScene);
        void PostScene(Scene *scene);

        SDL_Renderer *GetRenderer();
    
    private:
        int Init(int argc, char *argv[]);
        int Loop();
        int Clear();

        void EventReader();
        void Draw();

};