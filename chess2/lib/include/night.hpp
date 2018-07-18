#pragma once
#include "koma.hpp"
//#include "config/params.hpp"

class Night : public AbstKoma
{
public:
    explicit Night(int tate, int yoko, int player) : AbstKoma(tate, yoko, player) {}

    explicit Night(int tate, int yoko, int player, bool start) : AbstKoma(tate, yoko, player, start) {}

    void change_position(int new_tate, int new_yoko) override;

    int returnID() const override
    {
        return KomaID;
    }

private:
    const int KomaID = NIGHT;
};
