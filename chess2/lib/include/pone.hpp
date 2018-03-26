#pragma once
#include "koma.hpp"
#include "config/params.hpp"
#include <iostream>

class Pone : public AbstKoma
{
public:
    explicit Pone(int tate, int yoko, int player) : AbstKoma(tate, yoko, player) {}

    explicit Pone(int tate, int yoko, int player, bool start) : AbstKoma(tate, yoko, player, start) {}

    void change_position(int new_tate, int new_yoko) override;

    int returnID() const override
    {
        return KomaID;
    }

    /*~Pone()
    {
        std::cout << "デストラクタ" << std::endl;
    }*/


private:
    const int KomaID = PONE;
};
