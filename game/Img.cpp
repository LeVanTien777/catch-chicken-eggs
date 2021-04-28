#include "Img.h"
#include "init.h"

void showImg(SDL_Renderer*&renderer,std::string path,SDL_Rect *dsc){
    SDL_Texture* res = nullptr;
    SDL_Surface* load = IMG_Load(path.c_str());

    if(load != nullptr){
        SDL_SetColorKey(load, SDL_TRUE,SDL_MapRGB(load->format,0xCB,0xC8,0x9D));
        res = SDL_CreateTextureFromSurface(renderer,load);
    }else{
        logSDLError(std::cout,"load Image",true);
    }

    SDL_RenderCopy(renderer,res,NULL,dsc);

    SDL_DestroyTexture(res);
    SDL_FreeSurface(load);
    load    = nullptr;
    res     = nullptr;
}
