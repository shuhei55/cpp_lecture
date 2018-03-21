#pragma once
#include "koma.hpp"

class Pone : public AbstKoma
{
public:
    explicit Pone(int tate, int yoko, uint8_t player) : AbstKoma(tate, yoko, player) {}

    void change_position(int new_tate, int new_yoko) override
    {
        m_tate = new_tate;
        m_yoko = new_yoko;
    }

    uint8_t returnID() const
    {
        return KomaID;
    }

private:
    const uint8_t KomaID = 1;
};
