#pragma once

#include "SDL_render.h"
class GameObject {

public:
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual ~GameObject(){};
};