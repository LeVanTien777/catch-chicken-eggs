#include "Button.h"

bool Button::checked(toado mouse){
    if(mouse.x > dscButton.x && mouse.x <dscButton.w +dscButton.x && mouse.y > dscButton.y && mouse.y < dscButton.h + dscButton.y) return true;
    return false;
}

bool Button::click(toado oldMouse,toado mouse){
    if(checked(oldMouse) && checked(mouse)) return true;
    return false;
}

void Button::setup(const SDL_Rect& dsc){
    dscButton = dsc;
}
