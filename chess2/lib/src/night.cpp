#include "../include/night.hpp"

void Night::change_position(int new_tate, int new_yoko)
{
    if (new_tate == m_tate && new_yoko == m_yoko) {
        throw "wei";
    }
    if (std::abs(new_tate - m_tate) * std::abs(new_yoko - m_yoko) != 2) {
        throw "fui!";
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == 0) {
        throw std::make_shared<Night>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == AbstKoma::position.at(m_tate).at(m_yoko)->return_player()) {
        throw "いや違うだろ";
    }
    throw std::make_shared<Night>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
}
