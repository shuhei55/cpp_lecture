#include <array>
#include <iostream>
#include <string>
#include <math.h>

void play();
void change_p1();
void change_p2();
void each(int x, int y);
void check(int x, int y, int n, int k);
void check_0(int& c, int x, int y, int n, int k);
void check_1(int& c, int x, int y, int n, int k);
void check_2(int& c, int x, int y, int n, int k);
void check_3(int& c, int x, int y, int n, int k);
void check_4(int& c, int x, int y, int n, int k);
void check_5(int& c, int x, int y, int n, int k);
void check_6(int& c, int x, int y, int n, int k);
void check_7(int& c, int x, int y, int n, int k);

extern int gamemode;
extern std::array<std::array<int, 8>, 8> position;
