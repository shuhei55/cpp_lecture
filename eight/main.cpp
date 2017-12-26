#include <iostream>
#include <array>
#include "source.hpp"

using namespace std;

std::array<std::array<int, 3>, 3> a =
{{
    {0, 4, 2},
    {6, 3, 8},
    {1, 7, 5}
}}; //a.at(2).at(1) = 7

std::array<std::array<int, 3>, 3> b =
{{
    {0, 4, 2},
    {6, 3, 7},
    {1, 7, 5}
}}; //a.at(2).at(1) = 7

std::array<std::array<int, 3>, 3> c =
{{
    {0, 4, 2},
    {6, 5, 7},
    {1, 7, 3}
}}; //a.at(2).at(1) = 7

std::array<std::array<int, 3>, 3> d =
{{
    {0, 4, 2},
    {6, 3, 8},
    {1, 7, 5}
}}; //a.at(2).at(1) = 7

//[0]を動かす

int main()
{
    cout << check(b) << endl;
    cout << check(c) << endl;
    cout << check(d) << endl;
}
