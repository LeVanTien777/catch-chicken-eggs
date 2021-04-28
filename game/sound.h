#pragma once
#include <SDL_mixer.h>

typedef struct voice{
    Mix_Music* music;
    Mix_Chunk* effect1,*effect2;
    bool singingMusic,singingEffect1,singingEffect2;

    void create();
    void begin();

    void sing(void);

    void playEffect(int);

    void loadMus(void);

    void free(void);
}voice;
