#include <iostream>
#include "init.h"                      /// thư viện khởi tạo các đối tượng cần thiết
#include "crate.h"                     /// thư viện quản lý giỏ
#include "common_function.h"           /// các hàm dùng chung
#include "chicken.h"                   ///thư viện quản lý con gà
#include "Text.h"                      /// thư viện quản lý đưa chữ ra ngoài màn hình
#include "sound.h"                     ///thư viện quản lý âm thanh
#include "Button.h"

using namespace std;

luachon home(SDL_Renderer* ren);
void play(SDL_Renderer* ren,SDL_Rect screen);
bool choiLai(SDL_Renderer* ren);
void gameOver(SDL_Renderer*ren);

int main(int agrv,char* agrc[])
{
    init();                         ///khởi tạo thư viện SDL

    SDL_Renderer* ren;
    SDL_Window* win;
    SDL_Rect screen;

    screen.w = 1920;
    screen.h = 1080;

    createWindow(win,ren,screen); ///khởi tọa cửa sổ

    switch(home(ren)){
    case PLAY:
        do{
            play(ren,screen);
        }while(choiLai(ren));
        break;
    default:
        break;
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
    return 0;
}

luachon home(SDL_Renderer* ren){
    //return PLAY;

    SDL_Event e;

    SDL_Rect dscPlay,dscExit,dscName;

    Button play,exit;

    toado oldMouse,newMouse;

    dscName.x = 402;
    dscName.y = 99;
    dscName.w = 1116;
    dscName.h = 321;

    dscPlay.x = 271;
    dscPlay.y = 596;
    dscPlay.w = 487;
    dscPlay.h = 162;

    dscExit.x = 1163;
    dscExit.y = 596;
    dscExit.w = 487;
    dscExit.h = 162;

    play.setup(dscPlay);
    exit.setup(dscExit);

    showImg(ren,PATH_BKG,nullptr);
    setRendererColor(ren,BLUE_COLOR);
    SDL_RenderFillRect(ren,&dscPlay);
    SDL_RenderFillRect(ren,&dscExit);
    showText(ren,"PLAY",100,BLACK_COLOR,dscPlay);
    showText(ren,"EXIT",100,BLACK_COLOR,dscExit);
    showText(ren,"CATCH CHICKEN EGG",150,YELLOW_COLOR,dscName);

    showScreen(ren);
    while(1){
        while(SDL_PollEvent(&e) != 0){
            switch(e.type){
            case SDL_QUIT:
                return EXIT;
            case SDL_MOUSEMOTION:
                newMouse.x = e.motion.x;
                newMouse.y = e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                oldMouse = newMouse;
            case SDL_MOUSEBUTTONUP:
                if(play.click(oldMouse,newMouse) == true){
                    return PLAY;
                }

                if(exit.click(oldMouse,newMouse) == true){
                    return EXIT;
                }
                break;
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE)
                    return EXIT;
            }
        }
    }
}

void play(SDL_Renderer* ren,SDL_Rect screen){
    bool isrunning = true;
    int mang = 5;
    int trung_roi = 20;
    SDL_Event e;
    Chicken ga;
    Crate gio;
    SDL_Rect dscGio,dscGa,dscFormMenu,dscScore,dscMang,dscHeart,dscHeart2,dscSoTrung;
    Uint32 startTime;
    unsigned int score = 0;
    std::string msg;

    voice amThanh;

    amThanh.create();

    amThanh.music = Mix_LoadMUS(PATH_BGM.c_str());
    amThanh.effect1 = Mix_LoadWAV(PATH_EFECT_1.c_str());
    amThanh.effect2 = Mix_LoadWAV(PATH_EFECT_2.c_str());

    amThanh.singingMusic = true;
    amThanh.singingEffect1 = true;
    amThanh.singingEffect2 = true;

    amThanh.begin();

    amThanh.sing();

    dscGio.x = 1000;
    dscGio.y = 850;
    dscGio.w = dscGio.h = 300;

    dscGa.x = 900;
    dscGa.y = 0;
    dscGa.h = dscGa.w = 150;

    dscFormMenu.x = 0;
    dscFormMenu.y = 0;
    dscFormMenu.w = 400;
    dscFormMenu.h = 1080;

    dscScore.x = 70;
    dscScore.y = 500;
    dscScore.w = 100;
    dscScore.h = 40;

    dscMang.x = 70 + 40;
    dscMang.y = 650;
    dscMang.w = 50;
    dscMang.h = 40;

    dscSoTrung.x = 70 + 40;
    dscSoTrung.y = 730;
    dscSoTrung.w = 50;
    dscSoTrung.h = 40;

    dscHeart.x = 50;
    dscHeart.y = 640;
    dscHeart.w = 70;
    dscHeart.h = 70;

    dscHeart2.x = 50;
    dscHeart2.y = 720;
    dscHeart2.w = 60;
    dscHeart2.h = 60;

    screen.x = dscFormMenu.x + dscFormMenu.w;
    screen.y = 150;

    gio.create(dscGio,screen);
    ga.create(dscGa,screen);

    ///vòng lặp chính của game
    while(isrunning){
        startTime = SDL_GetTicks(); ///lấy thời gian hiện tại
        setRendererColor(ren,BLACK_COLOR);
        SDL_RenderClear(ren);

        ///nơi xử lý các sự kiện
        while(SDL_PollEvent(&e)){
            ///xem kiểu của sự kiện
            switch(e.type){
            ///bấn nút đỏ để tắt
            case SDL_QUIT:
                isrunning = false;
                break;
            ///sự kiện bàn phím
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                case SDLK_ESCAPE:
                    isrunning = false;
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    gio.chaneState(RIGHT);
                    break;
                case SDLK_LEFT:
                case SDLK_a:
                    gio.chaneState(LEFT);
                    break;
                }
                break;
                case SDL_KEYUP:
                    gio.getTimeNow();
                    gio.chaneState(NOPE);
                    break;
            }
        }


        showImg(ren,PATH_BKG,nullptr);
        int tam = gio.check(ga); ///va chạm với
        switch(tam){
            ///trứng
        case 2:
            amThanh.playEffect(1);
            score++;
            break;
            ///boom
        case 1:
            amThanh.playEffect(2);
            mang--;
            break;
        }

        if(mang == 0 || trung_roi ==  0){
            Mix_PauseMusic();
            SDL_Delay(200);
            showImg(ren,PATH_GAMEOVERSCREEN,nullptr);
            showScreen(ren);
            SDL_Delay(2000);
            goto GAME_OVER;
        }

        gio.update();

        gio.show(ren);

        trung_roi -= ga.update(ren);

        ga.show(ren);

        setRendererColor(ren,BROWN_COLOR);

        SDL_RenderFillRect(ren,&dscFormMenu); ///vẽ hcn đặc
        msg = "score: " + std::to_string(score);
        showText(ren,msg,40,WHITE_COLOR ,dscScore);

        showImg(ren,PATH_HEART,&dscHeart);
        msg = ": " + std::to_string(mang);
        showText(ren,msg,40,WHITE_COLOR ,dscMang);

        showImg(ren,PATH_EGG,&dscHeart2);
        msg = ": " + std::to_string(trung_roi);
        showText(ren,msg,40,WHITE_COLOR ,dscSoTrung);

        showScreen(ren);

        delay(startTime);

    }

    GAME_OVER:
 ///giải phóng các biến và thư viện
    amThanh.free();
    ga.free();

}

bool choiLai(SDL_Renderer* ren){
    //return false;

    SDL_Event e;

    SDL_Rect dscPlay,dscExit,dscName;

    Button play,exit;

    toado oldMouse,newMouse;

    dscName.x = 402;
    dscName.y = 99;
    dscName.w = 1116;
    dscName.h = 321;

    dscPlay.x = 271;
    dscPlay.y = 596;
    dscPlay.w = 487;
    dscPlay.h = 162;

    dscExit.x = 1163;
    dscExit.y = 596;
    dscExit.w = 487;
    dscExit.h = 162;

    play.setup(dscPlay);
    exit.setup(dscExit);

    showImg(ren,PATH_BKG,nullptr);
    setRendererColor(ren,BLUE_COLOR);
    SDL_RenderFillRect(ren,&dscPlay);
    SDL_RenderFillRect(ren,&dscExit);
    showText(ren,"YES",100,BLACK_COLOR,dscPlay);
    showText(ren,"NO",100,BLACK_COLOR,dscExit);
    showText(ren,"DO YOU WANT RESTART?",130,YELLOW_COLOR,dscName);

    showScreen(ren);
    while(1){
        while(SDL_PollEvent(&e) != 0){
            switch(e.type){
            case SDL_QUIT:
                return false;
            case SDL_MOUSEMOTION:
                newMouse.x = e.motion.x;
                newMouse.y = e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                oldMouse = newMouse;
            case SDL_MOUSEBUTTONUP:
                if(play.click(oldMouse,newMouse) == true){
                    return true;
                }

                if(exit.click(oldMouse,newMouse) == true){
                    return false;
                }
                break;
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE)
                    return false;
            }
        }
    }
}
