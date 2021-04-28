#pragma once
#include "init.h"
#include "egg.h"
#include <vector>

class Chicken{
private:
    SDL_Rect dsc,screen;
    state tt;
    Uint32 timeNow,timeOld;
    Uint32 timeEggNow,timeEggOld;
    std::vector<Egg> eggs;
    void rightMove(void);
    void leftMove(void);
    void de(SDL_Renderer*&);
public:
    void create(const SDL_Rect&,const SDL_Rect&);
    void show(SDL_Renderer*&);
    int update(SDL_Renderer*&);
    void getTimeNow();
    void free(void);
    void deleteEgg(int i);
    std::vector<Egg> getEggs(void) const { return eggs; }
};
