#pragma once
#include "koma.hpp"
#include "config/params.hpp"

class King : public AbstKoma
{
public:
    explicit King(int tate, int yoko, int player) : AbstKoma(tate, yoko, player) {}

    void change_position(int new_tate, int new_yoko) override;

    int returnID() const override
    {
        return KomaID;
    }

private:
    const int KomaID = KING;
};
