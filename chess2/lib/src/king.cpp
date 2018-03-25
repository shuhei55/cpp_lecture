#include "../include/king.hpp"

void King::change_position(int new_tate, int new_yoko)
{
    if (new_tate == m_tate && new_yoko == m_yoko) {
        throw "wei";
    }
    if (std::abs(new_tate - m_tate) > 1 || std::abs(new_yoko - m_yoko) > 1) {
        throw "うぇい";
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == 0) {
        throw std::make_shared<King>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == AbstKoma::position.at(m_tate).at(m_yoko)->return_player()) {
        throw "ほい";
    }
    throw std::make_shared<King>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
}
