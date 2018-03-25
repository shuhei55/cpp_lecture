#include "init.hpp"

void init()
{

    AbstKoma::position.at(0).at(0) = std::make_shared<Rook>(0, 0, PLAYER_A);
    AbstKoma::position.at(0).at(1) = std::make_shared<Night>(0, 1, PLAYER_A);
    AbstKoma::position.at(0).at(2) = std::make_shared<Bishop>(0, 2, PLAYER_A);
    AbstKoma::position.at(0).at(3) = std::make_shared<Queen>(0, 3, PLAYER_A);
    AbstKoma::position.at(0).at(4) = std::make_shared<King>(0, 4, PLAYER_A);
    AbstKoma::position.at(0).at(5) = std::make_shared<Bishop>(0, 5, PLAYER_A);
    AbstKoma::position.at(0).at(6) = std::make_shared<Night>(0, 6, PLAYER_A);
    AbstKoma::position.at(0).at(7) = std::make_shared<Rook>(0, 7, PLAYER_A);
    for (int i = 0; i < 8; i++) {
        AbstKoma::position.at(1).at(i) = std::make_shared<Pone>(1, i, PLAYER_A);
    }
    for (int i = 0; i < 8; i++) {
        AbstKoma::position.at(6).at(i) = std::make_shared<Pone>(6, i, PLAYER_B);
    }
    AbstKoma::position.at(7).at(0) = std::make_shared<Rook>(7, 0, PLAYER_B);
    AbstKoma::position.at(7).at(1) = std::make_shared<Night>(7, 1, PLAYER_B);
    AbstKoma::position.at(7).at(2) = std::make_shared<Bishop>(7, 2, PLAYER_B);
    AbstKoma::position.at(7).at(3) = std::make_shared<Queen>(7, 3, PLAYER_B);
    AbstKoma::position.at(7).at(4) = std::make_shared<King>(7, 4, PLAYER_B);
    AbstKoma::position.at(7).at(5) = std::make_shared<Bishop>(7, 5, PLAYER_B);
    AbstKoma::position.at(7).at(6) = std::make_shared<Night>(7, 6, PLAYER_B);
    AbstKoma::position.at(7).at(7) = std::make_shared<Rook>(7, 7, PLAYER_B);
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            AbstKoma::position.at(i).at(j) = std::make_shared<None>(i, j);
        }
    }
}
