#include "../include/rook.hpp"

void Rook::change_position(int new_tate, int new_yoko)
{
    if (new_tate - m_tate != 0 && new_yoko - m_yoko != 0) {
        throw "違うよ";
    } else if (new_tate - m_tate == 0 && new_yoko - m_yoko == 0) {
        throw "ちがうぜ";
    } else if (new_tate - m_tate == 0 && new_yoko - m_yoko != 0) {
        int vec_yoko = (new_yoko - m_yoko) / std::abs(new_yoko - m_yoko);
        for (int i = 1; i < std::abs(new_yoko - m_yoko); i++) {
            if (AbstKoma::position.at(m_yoko + i * vec_yoko).at(m_yoko)->return_player() != 0) {
                throw "なんかちがうわね";
            }
        }

    } else if (new_tate - m_tate != 0 && new_yoko - m_yoko == 0) {
        int vec_tate = (new_tate - m_tate) / std::abs(new_tate - m_tate);
        for (int i = 1; i < std::abs(new_tate - m_tate); i++) {
            if (AbstKoma::position.at(m_tate + i * vec_tate).at(m_yoko)->return_player() != 0) {
                throw "なんかちがわね";
            }
        }
    } else {
        throw "違うぜ";
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == 0) {
        throw std::make_shared<Rook>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
    }

    if (AbstKoma::position.at(new_tate).at(new_yoko)->return_player() == AbstKoma::position.at(m_tate).at(m_yoko)->return_player()) {
        throw "いや違うだろ";
    }
    throw std::make_shared<Rook>(new_tate, new_yoko, AbstKoma::position.at(m_tate).at(m_yoko)->return_player());
}
