#include "egg.h"
#include "common_function.h"
#include "common.h"

void Egg::create(SDL_Renderer*& renderer,const SDL_Rect val){
    td.x = val.x + val.w/2;
    td.y = val.y + val.h;
    td.w = td.h = 90;
    setMode();
    timeNow = timeOld = SDL_GetTicks();
    SDL_Surface* load = IMG_Load((mode ? PATH_EGG.c_str():PATH_BOOM.c_str()));
    eggsTexture = SDL_CreateTextureFromSurface(renderer,load);
    SDL_FreeSurface(load);
}
void Egg::setMode(){
    mode = random(0,3);

}

void Egg::show(SDL_Renderer*& renderer){
    showImg(renderer,(mode ? PATH_EGG:PATH_BOOM),&td);
}

void Egg::update(){

    td.y = td.y + 15;
}

bool Egg::check() const{
    return td.y + td.h > 1050;
}

void Egg::free(void){
    SDL_DestroyTexture(eggsTexture);
}
