#pragma once
#include <string>
#include "SDL_ttf.h"

class Settings {
public:
    static std::string mainFont;

    static void InitSettings(std::string fontName);
};