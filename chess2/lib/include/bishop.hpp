#pragma once
#include "koma.hpp"
#include "config/params.hpp"

class Bishop : public AbstKoma
{
public:
    explicit Bishop(int tate, int yoko, int player) : AbstKoma(tate, yoko, player) {}
    void change_position(int new_tate, int new_yoko) override;

    int returnID() const override
    {
        return KomaID;
    }

private:
    const int KomaID = BISHOP;
};
