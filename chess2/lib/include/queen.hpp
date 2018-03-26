#pragma once
#include "koma.hpp"
#include "config/params.hpp"

class Queen : public AbstKoma
{
public:
    explicit Queen(int tate, int yoko, int player) : AbstKoma(tate, yoko, player) {}

    explicit Queen(int tate, int yoko, int player, bool start) : AbstKoma(tate, yoko, player, start) {}

    void change_position(int new_tate, int new_yoko) override;

    int returnID() const override
    {
        return KomaID;
    }

private:
    const int KomaID = QUEEN;
};
