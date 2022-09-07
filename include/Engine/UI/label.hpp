#pragma once
#include "Engine/Object/image.hpp"
#include "SDL_ttf.h"
#include <string>
class Label : public ImageObject {
protected:
    std::string text = "Text";
    std::string fontName = "";
    int fontSize = 24;
    TTF_Font *font;

    SDL_Color color = {255,255,255};

public:
    Label(SDL_Renderer *renderer, std::string fontName, std::string text, int x, int y);
    Label(SDL_Renderer *renderer, std::string fontName, std::string text, int x, int y, int w, int h);
    Label(SDL_Renderer *renderer, std::string fontName, int x, int y);
    Label(SDL_Renderer *renderer, std::string fontName, int x, int y, int w, int h);

    void SetText(std::string newText);
    void SetFontName(std::string newFontName);
    void SetFontSize(int newFontSize);
};