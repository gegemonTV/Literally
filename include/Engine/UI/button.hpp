#pragma once

#include "Engine/Object/Listener/MouseClickListener.hpp"
#include "Engine/Object/gameobject.hpp"
#include "Engine/Object/image.hpp"
#include "Engine/UI/label.hpp"
class Button : public GameObject{
    ImageObject backgroundImageActive;
    Label label;

public:
    Button(SDL_Renderer *renderer, std::string text, std::string backgroundPath, int x, int y, int w, int h);
    Button(SDL_Renderer *renderer, std::string text, std::string backgroundPath, int x, int y);
    Button(SDL_Renderer *renderer, std::string text, int x, int y);
    Button(SDL_Renderer *renderer, int x, int y);

    void Draw() override;
    void Update() override;

    void CallOnMouseEvent(SDL_Event event) override;

    void SetOnMouseClickListener(MouseClickListener *mouseClickListener) override;
};