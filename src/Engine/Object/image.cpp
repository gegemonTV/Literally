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

ImageObject::ImageObject(SDL_Renderer *renderer, int x, int y) : GameObject(renderer, x, y) {
    if (renderer == nullptr)
        SDL_Log("renderer i snull");
    sourcePath = "";
    SDL_Surface *surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
    
    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 255, 255, 255, 255));

    imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

ImageObject::ImageObject(SDL_Renderer *renderer, int x, int y, int w, int h) : GameObject(renderer, x, y, w, h) {
    sourcePath = "";
    SDL_Surface *surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
    
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

    imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

ImageObject::ImageObject(SDL_Renderer *renderer, std::string path, int x, int y) : GameObject(renderer, x, y){
    sourcePath = path;
    this->imageTexture = IMG_LoadTexture(this->renderer, sourcePath.c_str());
    SDL_QueryTexture(imageTexture, NULL, NULL, &rect.w, &rect.h);
}

ImageObject::ImageObject(SDL_Renderer *renderer, std::string path, int x, int y, int w, int h) : GameObject(renderer, x, y, w, h) {
    sourcePath = path;
    this->imageTexture = IMG_LoadTexture(this->renderer, sourcePath.c_str());
}

void ImageObject::Draw() {
    if (imageTexture == NULL)
        SDL_LogError(100, "Empty texture");
    SDL_RenderCopy(renderer, imageTexture, NULL, &rect);
}

void ImageObject::Update(){}