#include <iostream>
#include <array>
#include "head.hpp"

using namespace std;

extern array<extern array<extern int, 8>, 8> position;

void check_0(int &c, int x, int y, int n, int k)
{
    c = 0;
    if (y == 0) {
    } else {
        if (position.at(y - 1).at(x) == k) {
        } else {
            for (int i = 1; i <= y; i++) {
                if (position.at(y - i).at(x) == n) {
                    continue;
                } else if (position.at(y - i).at(x) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y - j).at(x) = k;
                    }
                    c = 1;
                    break;
                } else {
                    break;
                }
            }
        }
    }
}
