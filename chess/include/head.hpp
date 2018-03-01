#include <iostream>
#include <array>
#include <math.h>
#include "../config/params.hpp"

extern std::array<std::array<int, 8>, 8> position;
extern int gamemode;
extern int number;
extern std::array<int, 2> pos_before;
extern std::array<int, 2> pos_after;

void show();
void input();
