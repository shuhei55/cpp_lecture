#include "../include/queen.hpp"

void Queen::change_position(int new_tate, int new_yoko)
{
    if (new_tate - m_tate == 0 && new_yoko - m_yoko == 0) {
        throw "tigauyo";
    } else if (new_tate - m_tate == 0) {
        int vec = (new_yoko - m_yoko) / std::abs(new_yoko - m_yoko);
        for (int i = 1; i < std::abs(new_yoko - m_yoko); i++) {
            if (AbstKoma::position.at(m_tate).at(m_yoko + i * vec)->return_player() != 0) {
                throw "asidho";
            }
        }
    } else if (new_yoko - m_yoko == 0) {
        int vec = (new_tate - m_tate) / std::abs(new_tate - m_tate);
        for (int i = 1; i < std::abs(new_tate - m_tate); i++) {
            if (AbstKoma::position.at(m_tate + i * vec).at(m_yoko)->return_player() != 0) {
                throw "asidhasda";
            }
        }
    } else if (std::abs(new_tate - m_tate) == std::abs(new_yoko - m_yoko)) {
        int vec_tate = (new_tate - m_tate) / std::abs(new_tate - m_tate);
        int vec_yoko = (new_yoko - m_yoko) / std::abs(new_yoko - m_yoko);
        for (int i = 1; i < std::abs(new_tate - m_tate); i++) {
            if (AbstKoma::position.at(m_tate + i * vec_tate).at(m_yoko + i * vec_yoko)->return_player() != 0) {
                throw "なんかちがわね";
            }
        }
    } else {
        throw "tigauze";
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == AbstKoma::position.at(m_tate).at(m_yoko)->return_player()) {
        throw "tigaunnjane";
    }

    throw std::make_shared<Queen>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
}
