#pragma once

#include "Engine/Object/Listener/MouseClickListener.hpp"
#include "SDL_events.h"
#include "SDL_rect.h"
#include "SDL_render.h"

class GameObject {
protected:
    MouseClickListener *mouseClickListener = new MouseClickListener();
    SDL_Rect rect;
    SDL_Renderer *renderer;
    SDL_Texture *imageTexture;


public:
    GameObject(SDL_Renderer *renderer, int x, int y);
    GameObject(SDL_Renderer *renderer, int x, int y, int w, int h);
    virtual void Draw() = 0;
    virtual void Update() = 0;

    virtual void SetOnMouseClickListener(class MouseClickListener *MouseClickListener);

    virtual void CallOnMouseEvent(SDL_Event event);

    bool IsInArea(int x, int y);

    SDL_Rect GetRectangle();

    virtual ~GameObject(){};
};