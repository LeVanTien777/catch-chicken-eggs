#pragma once
#include <SDL_ttf.h>
#include "init.h"
#include <string>
void showText(SDL_Renderer*,std::string,const int,SDL_Color,SDL_Rect);
SDL_Surface* getTextSurface(TTF_Font*,std::string,SDL_Color);
