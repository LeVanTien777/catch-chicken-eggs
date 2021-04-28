#include "sound.h"

void voice::create(){
    music           = nullptr;
    effect1          = nullptr;
    effect2          = nullptr;

    singingEffect1   = false;
    singingEffect2   = false;
    singingMusic    = false;
}


void voice::sing(void){
    if(music != nullptr){
        if(singingMusic == true && Mix_PlayingMusic())
            Mix_ResumeMusic();
        else
            Mix_PauseMusic();
    }
}
void voice::playEffect(int i){
    if(i == 1){
        if(effect1 != nullptr && singingEffect1 == true){
            Mix_PlayChannel(2,effect1,0);
        }
    }
    if(i == 2){
        if(effect2 != nullptr && singingEffect2 == true){
            Mix_PlayChannel(1,effect2,0);
        }
    }
}

void voice::free(void){
    Mix_FreeChunk(effect1);
    Mix_FreeChunk(effect2);
    Mix_FreeMusic(music);

    music           = nullptr;
    effect1         = nullptr;
    effect2         = nullptr;
}

void voice::begin(void){
    Mix_PlayMusic(music,-1);
}
