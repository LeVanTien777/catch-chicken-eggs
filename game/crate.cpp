#include "crate.h"
#include "common.h"

void Crate::create(const SDL_Rect& val,const SDL_Rect& val1)
{
    timeNow = timeOld = SDL_GetTicks();
    dsc.x = val.x;
    dsc.y = val.y;
    dsc.w = dsc.h = 130;
    screen = val1;
    tt = NOPE;
}

void Crate::show(SDL_Renderer*& renderer){
    showImg(renderer,PATH_GIO,&dsc);
}

void Crate::update(){
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
}

void Crate::chaneState(state val){
    if(tt != val)
        tt = val;

}

void Crate::leftMove(void){
    float t = (timeNow - timeOld)/1000.0;

    dsc.x -= t * SPEED_GIO;

    timeOld = timeNow;

}

void Crate::rightMove(void){
    float t = (timeNow - timeOld)/1000.0;

    dsc.x += t * SPEED_GIO;

    timeOld = timeNow;
}


void Crate::getTimeNow(void){

    timeNow = SDL_GetTicks();
    if(tt == NOPE)
        timeOld = timeNow;
}


int Crate::check(Chicken& c){
    int res = 0;
    for(int i = 0;i < c.getEggs().size();i++){
        if(c.getEggs()[i].td.x >= dsc.x - 20 &&
           dsc.x + dsc.w + 10 > c.getEggs()[i].td.x + c.getEggs()[i].td.w &&
           dsc.y + 65 <= c.getEggs()[i].td.y + c.getEggs()[i].td.h){
                res = (c.getEggs()[i].mode ? 2:1);
                c.deleteEgg(i);

           }
    }
    return res;
}
