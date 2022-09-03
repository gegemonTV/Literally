#include "Engine/engine.hpp"
#include "Engine/Scene/scene.hpp"
#include "SDL_events.h"
#include "SDL_video.h"

Engine::Engine(Scene *scene) {
    PostScene(scene);
}
Engine::~Engine() {}

int Engine::Run(int argc, char *argv[]) {
    int status = Init(argc, argv);
    status += Loop();
    status += Clear();
    return status;
}

int Engine::Init(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    if (SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }
    isPlaying = true;

    return 0;
}

int Engine::Loop() {
    while (isPlaying) {
        EventReader();
        currentScene->Update();
        Draw();
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
    if (event.type == SDL_QUIT) {
        isPlaying = false;
    }
}

void Engine::Draw() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    currentScene->Draw();
    SDL_RenderPresent(renderer);
}