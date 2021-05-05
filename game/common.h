#pragma once
#include <SDL.h>
using namespace std;
/// tính toán FPS cho game
const int FPS                                   = 30;
const int DELAY                                 = 1000/FPS;

///các hằng số tốc độ của game
const int SPEED_GIO                             = 450;                   ///px/s
const int SPEED_CHICKEN                         = 350;                   ///px/s
const int SPEED_EGG                             = 350;                   ///px/s

///khích thước cửa sổ chơi
const int height = 500;
const int width = 500;

/// đường dẫn tới các file quan trọng
const std::string WINDOW_TITLE                  = "CATCH CHICKEN EGGS";
const std::string PATH_GIO                      = "gio.png";
const std::string PATH_CHICKEN                  = "chicken.png";
const std::string PATH_BKG                      = "bkg1.jpg";
const std::string PATH_EGG                      = "eggs.png";
const std::string PATH_BOOM                     = "boom.png";
const std::string PATH_HEART                    = "heart.png";
const std::string PATH_GAMEOVERSCREEN           = "gameOverscrren.png";

const std::string PATH_FONT                     = "VNI-Lithos.ttf";

const std::string PATH_BGM                      = "Nhạc nền game bắn gà (Chicken Invaders).mp3";
const std::string PATH_EFECT_1                  = "y2mate (mp3cut.net).wav";
const std::string PATH_EFECT_2                  = "Tiếng boom (mp3cut.net) (1).wav";

///điịnh nghĩa các màu thường dùng
const SDL_Color CYAN_COLOR                      = {  0, 255, 255};
const SDL_Color BLUE_COLOR                      = {  0,   0, 255};
const SDL_Color ORANGE_COLOR                    = {255, 165,   0};
const SDL_Color YELLOW_COLOR                    = {255, 255,   0};
const SDL_Color LIME_COLOR                      = {  0, 255,   0};
const SDL_Color PURPLE_COLOR                    = {128,   0, 128};
const SDL_Color RED_COLOR                       = {255,   0,   0};
const SDL_Color GREEN_COLOR                     = {  0, 128,   0};
const SDL_Color WHITE_COLOR                     = {255, 255, 255};
const SDL_Color BLACK_COLOR                     = {  0,   0,   0};
const SDL_Color BROWN_COLOR                     = {139, 143,  78};
