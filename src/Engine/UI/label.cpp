#include "Engine/UI/label.hpp"
#include "Engine/Object/image.hpp"
#include "Engine/Settings/settings.hpp"
#include "SDL_log.h"
#include "SDL_pixels.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_ttf.h"
#include <string>


Label::Label(SDL_Renderer *renderer, std::string fontName, std::string text, int x, int y, int w, int h) : ImageObject(renderer, x, y, w, h) {
    this->fontName = fontName;
    this->text = text;
    font = TTF_OpenFont(fontName.c_str(), fontSize);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    imageTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    rect.w = w;
    rect.h = h;
    if (w == 0)
        TTF_SizeText(font, text.c_str(), &rect.w, NULL);
    if (h == 0)
        TTF_SizeText(font, text.c_str(), NULL, &rect.h);
}

Label::Label(SDL_Renderer *renderer, std::string fontName, int x, int y) : Label(renderer, fontName, "text", x, y, 0, 0){}

Label::Label(SDL_Renderer *renderer, std::string fontName, std::string text, int x, int y) : Label(renderer, fontName, text, x, y, 0, 0) {}
Label::Label(SDL_Renderer *renderer, std::string fontName, int x, int y, int w, int h):Label(renderer, fontName, "text", x, y, w, h){}

void Label::SetFontName(std::string newFontName) {
    this->fontName = newFontName;
    font = TTF_OpenFont(newFontName.c_str(), fontSize);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    imageTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (rect.w == 0)
        TTF_SizeText(font, text.c_str(), &rect.w, NULL);
    if (rect.h == 0)
        TTF_SizeText(font, text.c_str(), NULL, &rect.h);
}

void Label::SetFontSize(int newFontSize) {
    this->fontSize = newFontSize;
    font = TTF_OpenFont(fontName.c_str(), fontSize);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    imageTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (rect.w == 0)
        TTF_SizeText(font, text.c_str(), &rect.w, NULL);
    if (rect.h == 0)
        TTF_SizeText(font, text.c_str(), NULL, &rect.h);
}

void Label::SetText(std::string newText) {
    this->text = newText;
    font = TTF_OpenFont(fontName.c_str(), fontSize);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    imageTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (rect.w == 0)
        TTF_SizeText(font, text.c_str(), &rect.w, NULL);
    if (rect.h == 0)
        TTF_SizeText(font, text.c_str(), NULL, &rect.h);
}