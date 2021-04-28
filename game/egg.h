#pragma once
#include "init.h"

typedef struct Egg{
    SDL_Rect td,screen;
    Uint32 timeNow,timeOld;
    bool mode;
    SDL_Texture* eggsTexture;

    void create(SDL_Renderer*&,const SDL_Rect);
    void update();
    void show(SDL_Renderer*&);

    bool check()const;

    void move();

    void free(void);
private:
    void setMode();
} Egg;
