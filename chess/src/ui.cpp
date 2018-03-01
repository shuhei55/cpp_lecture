#include "../include/head.hpp"

std::array<std::array<int, 8>, 8> position = {
    {{ROOK, NIGHT, BISHOP, QUEEN, KING, BISHOP, NIGHT, ROOK},
        {PONE, PONE, PONE, PONE, PONE, PONE, PONE, PONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        {PONE, PONE, PONE, PONE, PONE, PONE, PONE, PONE},
        {ROOK, NIGHT, BISHOP, QUEEN, KING, BISHOP, NIGHT, ROOK}}};

int number;
std::array<int, 2> pos_before;
std::array<int, 2> pos_after;

void show()
{
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            std::cout << position.at(i).at(j) << " ";
        }
        std::cout << "\n";
    }
}

void input()
{
    std::cout << "駒の番号と駒の位置と移動先" << std::endl;
    std::cin >> number >> pos_before.at(0) >> pos_before.at(1) >> pos_after.at(0) >> pos_after.at(1);
}
