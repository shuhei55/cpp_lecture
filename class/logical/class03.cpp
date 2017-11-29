#include <iostream>

using namespace std;

struct Length_m
{
    Length_m() = default;

    Length_m(double len) : value(len){}

    Length_m operator+(Length_m rhs) const
    {
        return Length_m{value + rhs.value};
    }

    private:
    double value;

};


int main()
{

}
