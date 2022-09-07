#include "Engine/Settings/settings.hpp"
#include "Engine/engine.hpp"
#include "Engine/Scene/scene.hpp"
#include "SDL.h"
#include "SDL_events.h"
#include "SDL_log.h"
#include "SDL_mouse.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_timer.h"
#include "SDL_ttf.h"
#include "SDL_video.h"

Engine::~Engine() {}

int Engine::Run(int argc, char *argv[], Scene *firstScene) {
    int status = Init(argc, argv);
    PostScene(firstScene);
    status += Loop();
    status += Clear();
    return status;
}

int Engine::Init(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 2;
    }

    if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }
    if (TTF_Init()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to init TTF: %s", TTF_GetError());
        return 4;
    }
    SDL_SetWindowResizable(window, SDL_FALSE);

    Settings::InitSettings("assets/fonts/font.ttf");
    isPlaying = true;

    return 0;
}

int Engine::Loop() {

    next_tick = SDL_GetTicks64();

    int loops;
    float interpolation;

    while (isPlaying) {
        loops = 0;
        EventReader();
        while (SDL_GetTicks64() > next_tick && loops < MAX_FRAME_SKIP) {
            currentScene->Update();
            next_tick += SKIP_TICKS;
            loops++;
        }

        interpolation = float (SDL_GetTicks64() + SKIP_TICKS - next_tick) / float (SKIP_TICKS);
        
        Draw(interpolation);
    }
    return 0;
}

int Engine::Clear() {
    currentScene->OnDestroy();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

void Engine::PostScene(Scene *scene) {
    if (currentScene != nullptr)
        currentScene->OnDestroy();
    currentScene = scene;
    currentScene->SetEngine(this);
    currentScene->OnCreate();
}

void Engine::EventReader() {
    SDL_PollEvent(&event);
    int x, y;
    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
        SDL_GetMouseState(&x, &y);
        currentScene->DispatchMouseEvents(x, y, event);
    }
    if (event.type == SDL_QUIT) {
        isPlaying = false;
    }
}

void Engine::Draw(float interpolation) {
    SDL_RenderClear(renderer);
    currentScene->Draw();  // TODO: Add interpolation and prediction into scene drawer
    SDL_RenderPresent(renderer);
}

SDL_Renderer *Engine::GetRenderer() {
    return renderer;
}