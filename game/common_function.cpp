#include "common_function.h"
#include "common.h"
#include <random>
void delay(Uint32 startTime){
    Uint32 farmeTime;

    farmeTime = SDL_GetTicks() - startTime;

    if(farmeTime < DELAY)
        SDL_Delay(farmeTime);
}

void showScreen(SDL_Renderer*& renderer){
    SDL_RenderPresent(renderer);
}

int random(int a,int b){
    return a + rand() % (b + 1 - a);
}
