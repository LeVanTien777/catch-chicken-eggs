#pragma once
#include "init.h"
#include "chicken.h"


/**
    dsc nơi hiện thị cái giỏ
    screen khích thước thông số của màn hình chơi
    tt trạng thái chuyển động của cái giỏ
    timeNow,timeOld 2 biến kiểm soat thời gian
*/

class Crate{
private:
    SDL_Rect dsc,screen;
    state tt;
    Uint32 timeNow,timeOld;
    void rightMove(void);
    void leftMove(void);
public:
    void create(const SDL_Rect&,const SDL_Rect&); /// hàm khởi tạo đối tượng
    void show(SDL_Renderer*&); /// hàm hiển thị đối tượng
    void chaneState(state); /// thay đổi trnagj thaios chuyển động
    void update();     ///hàm cập nhật
    void getTimeNow(void); /// hàm cập nhật thời gian hiện tại
    int check(Chicken&);  /// hàm kiểm tra ăn trứng || boom || không ăn

};
