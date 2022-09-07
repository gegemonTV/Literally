
#include "Engine/Object/gameobject.hpp"
#include "SDL_log.h"
#include "SDL_rect.h"
#include "SDL_render.h"

GameObject::GameObject(SDL_Renderer *renderer, int x, int y, int w, int h) {
    this->renderer = renderer;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

GameObject::GameObject(SDL_Renderer *renderer, int x, int y) : GameObject(renderer, x, y, 100, 30){}

SDL_Rect GameObject::GetRectangle() {
    return rect;
}

void GameObject::SetOnMouseClickListener(class MouseClickListener *mouseClickListener) {
    this->mouseClickListener = mouseClickListener;
}

void GameObject::CallOnMouseEvent(SDL_Event event) {
    switch (event.type) {
    case SDL_MOUSEBUTTONDOWN: 
        mouseClickListener->OnMouseDown();
        break;
    case SDL_MOUSEBUTTONUP:
        mouseClickListener->OnMouseUp();
        break;
    case SDL_MOUSEMOTION:
        mouseClickListener->OnMouseReleased();
        break;
    default:
        SDL_Log("WTF DUDE!?");
        break;
    }
}

bool GameObject::IsInArea(int x, int y){
    return x <= rect.x + rect.w && x >= rect.x && y <= rect.y + rect.h && y >= rect.y;
}