#pragma once
#include <iostream>
#include <array>
#include <math.h>

extern int gamemode;
extern std::array<int, 2> pos_before;
extern std::array<int, 2> pos_after;

void show();
void input();
void change(int now_tate, int now_yoko, int new_tate, int new_yoko);
