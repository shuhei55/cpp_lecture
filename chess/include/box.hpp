#pragma once
#include "params.hpp"

class Box
{
public:
    explicit Box()
    {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                position.at(i).at(i) = NONE;
            }
        }
    }

    int check(uint8_t tate, uint8_t yoko)
    {
        return position.at(tate).at(yoko);
    }


private:
    std::array<std::array<uint8_t, 8>, 8> position;
};
