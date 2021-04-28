#include "Text.h"
#include "common.h"

void showText(SDL_Renderer* renderer,std::string msg,const int size,SDL_Color color,SDL_Rect dsc){
    TTF_Font *font = TTF_OpenFont(PATH_FONT.c_str(),size);
    if(font == nullptr){
        std::cout<<"load font: "<<SDL_GetError();
        exit(1);
    }
    SDL_Surface *textSurface = TTF_RenderText_Solid(font,msg.c_str(),color);
    SDL_Texture *text = SDL_CreateTextureFromSurface(renderer,textSurface);

    int w,h;
    SDL_QueryTexture(text,NULL,NULL,&w,&h);
    dsc.x += (dsc.w - w)/2;
    dsc.y += (dsc.h-h)/2;
    dsc.w = w;
    dsc.h = h;
    SDL_RenderCopy(renderer,text,NULL,&dsc);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);
    TTF_CloseFont(font);

    text = nullptr;
    textSurface = nullptr;
    font = nullptr;
}
