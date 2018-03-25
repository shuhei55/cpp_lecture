#include "../include/bishop.hpp"

void Bishop::change_position(int new_tate, int new_yoko)
{
    if (new_tate == m_tate && new_yoko == m_yoko) {
        throw "wei";
    }
    if (std::abs(new_tate - m_tate) != std::abs(new_yoko - m_yoko)) {
        throw "なんか違うよ";
    }
    int vec_tate = (new_tate - m_tate) / std::abs(new_tate - m_tate);
    int vec_yoko = (new_yoko - m_yoko) / std::abs(new_yoko - m_yoko);
    for (int i = 1; i < std::abs(new_tate - m_tate); i++) {
        if (AbstKoma::position.at(m_tate + i * vec_tate).at(m_yoko + i * vec_yoko)->return_player() != 0) {
            throw "なんかちがわね";
        }
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == 0) {
        throw std::make_shared<Bishop>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == AbstKoma::position.at(m_tate).at(m_yoko)->return_player()) {
        throw "いや違うだろ";
    }
    throw std::make_shared<Bishop>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
}
