#include "chicken.h"
#include <random>

void Chicken::create(const SDL_Rect& val,const SDL_Rect& val1){
    timeEggNow = timeEggOld = timeNow = timeOld = SDL_GetTicks();
    dsc.x = val.x;
    dsc.y = val.y;
    dsc.w = dsc.h = 230;
    tt = RIGHT;
    screen = val1;
}

int Chicken::update(SDL_Renderer*& renderer){
    int res = 0;
    timeEggNow = SDL_GetTicks();
    if(timeEggNow - timeEggOld >= 1000){
        timeEggOld = timeEggNow;
        de(renderer);
    }

    for(int i = 0;i<eggs.size();i++){
        eggs[i].update();
        if(eggs[i].check()){
            if(eggs[i].mode != 0){
                res++;
            }
            eggs[i].free();
            eggs.erase(eggs.begin()+i);

        }
    }

    if(dsc.x < screen.x){
        dsc.x = screen.x;
        tt = RIGHT;
    }else if(dsc.x + dsc.w > screen.w){
        dsc.x = dsc.x - dsc.w;
        tt = LEFT;
    }
    switch(tt){
    case LEFT:
        leftMove();
        break;
    case RIGHT:
        rightMove();
        break;
    default:
        break;
    }
    getTimeNow();
    return res;
}


void Chicken::rightMove(void){
    float t = (timeNow - timeOld)/1000.0;

    dsc.x += t * SPEED_CHICKEN;

    timeOld = timeNow;
}


void Chicken::leftMove(void){
    float t = (timeNow - timeOld)/1000.0;

    dsc.x -= t * SPEED_CHICKEN;

    timeOld = timeNow;

}

void Chicken::getTimeNow(void){

    timeNow = SDL_GetTicks();
    if(tt == NOPE)
        timeOld = timeNow;
}

void Chicken::de(SDL_Renderer*& renderer){
    Egg tem;
    tem.create(renderer,dsc);
    tem.screen = screen;
    eggs.push_back(tem);
}

void Chicken::free(void){
    for(Egg &c:eggs){
        c.free();
    }
    eggs.clear();
}


void Chicken::show(SDL_Renderer*& ren){
    showImg(ren,PATH_CHICKEN,&dsc);
    for(Egg &c:eggs){
        SDL_RenderCopy(ren,c.eggsTexture,nullptr,&c.td);
    }
}

void Chicken::deleteEgg(int i){
    eggs[i].free();
    eggs.erase(eggs.begin()+i);
}
