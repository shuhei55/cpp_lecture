#pragma once
#include "koma.hpp"
//#include "config/params.hpp"

class None : public AbstKoma
{
public:
    explicit None(int tate, int yoko) : AbstKoma(tate, yoko, 0) {}

    void change_position(int new_tate, int new_yoko) override
    {
        throw "ふざけんな！";
    }

    int returnID() const override
    {
        return KomaID;
    }

private:
    const int KomaID = NONE;
};
