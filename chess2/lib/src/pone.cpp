#include "../include/pone.hpp"

void Pone::change_position(int new_tate, int new_yoko)
{
    if (new_tate == m_tate && new_yoko == m_yoko) {
        throw "ufaoudoffh";
    } else if (new_tate == m_tate + 1 && new_yoko == m_yoko) {
        if (AbstKoma::position.at(new_tate).at(m_yoko)->return_player() != 0) {
            throw "gdosgodua";
        }
    } else if (new_tate == m_tate + 1 && std::abs(new_yoko - m_yoko) == 1) {
        if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == 0 && AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == AbstKoma::position.at(m_tate).at(m_yoko)->return_player()) {
            throw "gdosgodua";
        }
    } else {
        throw "wehi";
    }

    throw std::make_shared<Pone>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
}
