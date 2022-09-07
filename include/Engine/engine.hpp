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

    const int TICKS_PER_SECOND = 60;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAME_SKIP = 5;

    Uint64 next_tick = 0;

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
        void Draw(float interpolation);

};