#pragma once
#include <cstdint>
#include <array>
#include <memory>
#include "config/params.hpp"
class AbstKoma
{
public:
    explicit AbstKoma(int tate, int yoko, int player) : m_tate(tate), m_yoko(yoko), m_player(player), m_start(false) {}

    explicit AbstKoma(int tate, int yoko, int player, bool start) : m_tate(tate), m_yoko(yoko), m_player(player), m_start(start) {}

    /*bool check_alive() const
    {
        return !(m_tate == -1 || m_yoko == -1);
    }*/

    virtual void change_position(int new_tate, int new_yoko) = 0;

    virtual int returnID() const = 0;

    int return_player() const
    {
        return m_player;
    }

    bool is_start() const
    {
        return m_start;
    }

    /*int return_tate() const
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
    }*/

    static std::array<std::array<std::shared_ptr<AbstKoma>, 8>, 8> position;

protected:
    int m_tate, m_yoko;
    int m_player;
    bool m_start;
};
