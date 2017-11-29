#include <iostream>
#include <array>
#include <string>
#include "head.hpp"

using namespace std;

int gamemode = 1;

int main()
{
    while(true)
    {
        play();
        if (gamemode == 1) {
            change_p1();
        } else {
            change_p2();
        }
    }

}
