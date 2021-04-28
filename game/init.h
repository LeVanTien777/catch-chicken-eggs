#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Img.h"
#include "common.h"

typedef struct toado{
    int x,y;
    bool operator==(const toado &a) const {
        return (x == a.x && y == a.y);
    }
} toado;

typedef enum luachon{
    NONE,
    PLAY,
    EXIT
} luachon;

typedef enum state{

    FALLING,
    RIGHT,
    LEFT,
    NOPE
} state;

void init();///khởi tạo các thư viện
void logSDLError(std::ostream&,const std::string&,bool); /// hiển thị lỗi sdl
void createWindow(SDL_Window* &window, SDL_Renderer* &renderer,SDL_Rect &s);
void waitUntilKeyPressed();
void setRendererColor(SDL_Renderer*&,const SDL_Color&);
