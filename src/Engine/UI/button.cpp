#include "Engine/UI/button.hpp"
#include "Engine/Object/gameobject.hpp"
#include "Engine/Object/image.hpp"
#include "Engine/Settings/settings.hpp"
#include "Engine/UI/label.hpp"
#include "SDL_events.h"
#include "SDL_rect.h"
#include "SDL_render.h"


Button::Button(SDL_Renderer *renderer, int x, int y) : 
GameObject(renderer, x, y),
backgroundImageActive(renderer, x, y),
label(renderer, Settings::mainFont, x, y) {
}

Button::Button(SDL_Renderer *renderer, std::string text, int x, int y) :
Button(renderer, x, y){
    label = Label(renderer, Settings::mainFont, text, x, y);
}

Button::Button(SDL_Renderer *renderer, std::string text, std::string backgroundPath, int x, int y) :
Button(renderer, text, x, y) {
    backgroundImageActive = ImageObject(renderer, backgroundPath, x, y);
}

Button::Button(SDL_Renderer *renderer, std::string text, std::string backgroundPath, int x, int y, int w, int h) : 
Button(renderer, x, y) {
    backgroundImageActive = ImageObject(renderer, backgroundPath, x, y, w, h);
    label = Label(renderer, Settings::mainFont, text, x, y, w, h);
}
void Button::Draw() {
    backgroundImageActive.Draw();
    label.Draw();
}

void Button::CallOnMouseEvent(SDL_Event event) {
    backgroundImageActive.CallOnMouseEvent(event);
}

void Button::SetOnMouseClickListener(class MouseClickListener *mouseClickListener) {
    backgroundImageActive.SetOnMouseClickListener(mouseClickListener);
}

void Button::Update() {

}