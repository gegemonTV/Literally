#pragma once

#include "Engine/Object/gameobject.hpp"
#include "SDL_events.h"
#include "SDL_rect.h"
#include "SDL_render.h"

#include <string>

class GameObject;

class ImageObject : public GameObject {

    std::string sourcePath = "";

    SDL_Renderer *renderer;
    SDL_Texture *imageTexture;
    SDL_Rect rect;

protected:
    MouseClickListener *mouseClickListener;

public:
    ImageObject(SDL_Renderer *renderer, int x, int y);
    ImageObject(SDL_Renderer *renderer, int x, int y, int w, int h);
    ImageObject(SDL_Renderer *renderer, std::string path, int x, int y);
    ImageObject(SDL_Renderer *renderer, std::string path, int x, int y, int w, int h);

    void Draw() override;
    void Update() override;
    void SetOnMouseClickListener(class MouseClickListener *MouseClickListener);

    void CallOnMouseEvent(SDL_Event event);

    bool IsInArea(int x, int y);


    ~ImageObject() override = default;

};