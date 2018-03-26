#include "config/params.hpp"
#include "ui.hpp"
#include "init.hpp"

std::array<int, 2> pb;
std::array<int, 2> pa;

int gamemode = PLAYER_A;

void show()
{
    std::cout << "     ０  １  ２  ３  ４  ５  ６  ７" << std::endl;
    for (int i = 0; i <= 7; i++) {
        std::cout << "   ---------------------------------" << std::endl;
        std::cout << " " << i << " |";
        for (int j = 0; j <= 7; j++) {
            std::cout << " " << AbstKoma::position.at(i).at(j)->returnID() << " |";
        }
        std::cout << "\n";
    }
    std::cout << "   ---------------------------------" << std::endl;
}

void input()
{
    std::cout << "駒の番号と駒の位置と移動先 : Usage Before_tate, Before_yoko, After_tate, After_yoko" << std::endl;
    try {
        std::cin >> pb.at(0) >> pb.at(1) >> pa.at(0) >> pa.at(1);
        if (!(pb.at(0) >= 0 && pb.at(0) < 8 && pb.at(1) >= 0 && pb.at(1) < 8 && pa.at(0) >= 0 && pa.at(0) < 8 && pa.at(1) >= 0 && pa.at(1) < 8)) {
            throw "hoge";
        }
        if (AbstKoma::position.at(pb.at(0)).at(pb.at(1))->return_player() != gamemode) {
            throw "fuga";
        }
        change(pb.at(0), pb.at(1), pa.at(0), pa.at(1));
        gamemode *= -1;
    } catch (const char* str) {
        std::cout << str << std::endl;
    }
}

void change(int now_tate, int now_yoko, int new_tate, int new_yoko)
{
    try {
        AbstKoma::position.at(now_tate).at(now_yoko)->change_position(new_tate, new_yoko);
    } catch (std::shared_ptr<Bishop> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = std::make_shared<None>(now_tate, now_yoko);

    } catch (std::shared_ptr<King> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = std::make_shared<None>(now_tate, now_yoko);

    } catch (std::shared_ptr<Rook> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = std::make_shared<None>(now_tate, now_yoko);

    } catch (std::shared_ptr<Night> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = std::make_shared<None>(now_tate, now_yoko);

    } catch (std::shared_ptr<Queen> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = std::make_shared<None>(now_tate, now_yoko);

    } catch (std::shared_ptr<Pone> ed) {
        AbstKoma::position.at(new_tate).at(new_yoko) = ed;
        AbstKoma::position.at(now_tate).at(now_yoko) = std::make_shared<None>(now_tate, now_yoko);
    }
}
