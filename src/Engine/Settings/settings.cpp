#include "Engine/Settings/settings.hpp"
#include "SDL_log.h"
#include "SDL_ttf.h"
#include <string>

std::string Settings::mainFont = "";

void Settings::InitSettings(std::string fontName) {
    mainFont = fontName;
    
}