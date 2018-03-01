#include "include/head.hpp"

int main()
{
    int gamemode = PLAYER_A;
    while (true) {
        if (gamemode == PLAYER_A) {
            std::cout << "PLAYER_Aの番です" << std::endl;
            show();
            input();
        } else if (gamemode == PLAYER_B) {
            std::cout << "PLAYER_Bの番です" << std::endl;
            show();
            input();
        } else {
            show();
        }
    }
}
