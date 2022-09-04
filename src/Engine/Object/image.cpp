#include "Engine/Object/image.hpp"
#include "Engine/Object/gameobject.hpp"
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
    rect.w = 100;
    rect.h = 30;
    rect.x = x;
    rect.y = y;
    this->imageTexture = IMG_LoadTexture(this->renderer, sourcePath.c_str());
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
    SDL_Log("Drawing image");
    SDL_RenderCopy(renderer, imageTexture, NULL, &rect);
}

void ImageObject::Update(){}