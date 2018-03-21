#pragma once
#include <cstdint>
class AbstKoma
{
public:
    explicit AbstKoma(int tate, int yoko, uint8_t player) : m_tate(tate), m_yoko(yoko), m_player(player) {}

    bool check_alive() const
    {
        return !(m_tate == 0 || m_yoko == 0);
    }

    virtual void change_position(int new_tate, int new_yoko) = 0;

    int return_tate() const
    {
        return m_tate;
    }

    int return_yoko() const
    {
        return m_yoko;
    }

    void removed()
    {
        m_tate = -1;
        m_yoko = -1;
    }

protected:
    int m_tate, m_yoko;

private:
    uint8_t m_player;
};
