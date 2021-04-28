#include "init.h"
#include <ctime>
#include <time.h>

void logSDLError(std::ostream &os,const std::string &msg,bool fatal = false){
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void createWindow(SDL_Window* &window, SDL_Renderer* &renderer,SDL_Rect &screen)
{
    #define SCREEN_HEIGHT screen.h
    #define SCREEN_WIDTH screen.w

   window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    ///Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    ///Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr)
        logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        //SDL_Delay(100);
    }
}

void init(){
    srand((int)time(NULL));     /// khởi tại sinh số ngẫu nhiên

    ///khởi tạo thư viện sdl
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    ///khởi tạo thư viện text
    TTF_Init();

    ///khởi tạo luồng âm thanh
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
        logSDLError(std::cout,"Mix_OpenAudio",true);

}

void setRendererColor(SDL_Renderer*&ren,const SDL_Color& c){
    SDL_SetRenderDrawColor(ren,c.r,c.g,c.b,c.a);
}
