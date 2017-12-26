#include <iostream>
#include <array>
#include "source.hpp"

int check(std::array<std::array<int, 3>, 3> b) {
    int h = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a.at(i).at(j) != b.at(i).at(j)) {
                h++;
            }
        }
    }
    return h;
}

