#include "Engine/Object/image.hpp"
#include "Engine/Object/gameobject.hpp"
#include "SDL_events.h"
#include "SDL_image.h"
#include "SDL_log.h"
#include "SDL_pixels.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include <string>

ImageObject::ImageObject(SDL_Renderer *renderer, int x, int y) {
    this->renderer = renderer;
    if (renderer == nullptr)
        SDL_Log("renderer i snull");
    sourcePath = "";
    rect.w = 100;
    rect.h = 30;
    rect.x = x;
    rect.y = y;
    SDL_Surface *surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
    
    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 255, 255, 255, 255));

    imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

ImageObject::ImageObject(SDL_Renderer *renderer, int x, int y, int w, int h) {
    this->renderer = renderer;
    sourcePath = "";
    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;
    SDL_Surface *surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
    
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

    imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

ImageObject::ImageObject(SDL_Renderer *renderer, std::string path, int x, int y) {
    this->renderer = renderer;
    sourcePath = path;
    rect.x = x;
    rect.y = y;
    this->imageTexture = IMG_LoadTexture(this->renderer, sourcePath.c_str());
    SDL_QueryTexture(imageTexture, NULL, NULL, &rect.w, &rect.h);
}

ImageObject::ImageObject(SDL_Renderer *renderer, std::string path, int x, int y, int w, int h) {
    this->renderer = renderer;
    sourcePath = path;
    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;
    this->imageTexture = IMG_LoadTexture(this->renderer, sourcePath.c_str());
}

void ImageObject::Draw() {
    if (imageTexture == NULL)
        SDL_LogError(100, "Empty texture");
    SDL_RenderCopy(renderer, imageTexture, NULL, &rect);
}


void ImageObject::SetOnMouseClickListener(class MouseClickListener *mouseClickListener) {
    this->mouseClickListener = mouseClickListener;
}

void ImageObject::CallOnMouseEvent(SDL_Event event) {
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

bool ImageObject::IsInArea(int x, int y){
    return x <= rect.x + rect.w && x >= rect.x && y <= rect.y + rect.h && y >= rect.y;
}

void ImageObject::Update(){}