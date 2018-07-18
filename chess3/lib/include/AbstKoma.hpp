#pragma once

class AbstKoma
{
public:
    AbstKoma(int tate, int yoko, int player) : m_tate(tate), m_yoko(yoko), m_player(player) {}

    virtual void change_position(int new_tate, int new_yoko);

    int return_tate() const { return m_tate }
    int return_yoko() const { return m_yoko }
    int return_player() const { return m_player }

private:
    std::weak_ptr<Board> game_board;
    int m_player, m_tate, m_yoko;
};
