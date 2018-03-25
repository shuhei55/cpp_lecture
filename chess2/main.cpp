#include "init/init.hpp"
#include <iostream>
#include "init/ui.hpp"

int main()
{
    init();

    while (true) {
        if (gamemode == PLAYER_A) {
            std::cout << "Aの番" << std::endl;
            show();
            input();
        } else if (gamemode == PLAYER_B) {
            std::cout << "Bの番" << std::endl;
            show();
            input();
        } else {
            show();
        }
    }
}
