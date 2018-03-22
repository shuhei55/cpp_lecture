#include "config/params.hpp"
#include "ui.hpp"
#include "init.hpp"

std::array<int, 2> pos_before;
std::array<int, 2> pos_after;

int gamemode = PLAYER_A;

void show()
{
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            //std::cout << position.at(i).at(j) << " ";
        }
        std::cout << "\n";
    }
}

void input()
{
    std::cout << "駒の番号と駒の位置と移動先" << std::endl;
    std::cin >> pos_before.at(0) >> pos_before.at(1) >> pos_after.at(0) >> pos_after.at(1);
}

void change(int now_tate, int now_yoko, int new_tate, int new_yoko)
{
    try {
        AbstKoma::position.at(now_tate).at(now_yoko)->change_position(new_tate, new_yoko);
    } catch (const char* str) {
        std::cout << str << std::endl;
    } catch (std::shared_ptr<Bishop> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = nullptr;
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = nullptr;
    } catch (std::shared_ptr<King> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = nullptr;
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = nullptr;
    }
}
