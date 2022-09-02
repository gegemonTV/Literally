#pragma once

#include "SDL.h"
class Engine {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Event event;

    public:
        Engine();
        ~Engine();

        int Run(int argc, char* argv[]);
    
    private:
        int Init(int argc, char *argv[]);
        int Loop();
        int Clear();

};