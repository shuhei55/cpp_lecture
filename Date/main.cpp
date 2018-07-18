#include "year.hpp"
#include <iostream>

using namespace std;

int main()
{
    Year hoge;
    cout << hoge << endl;
    Year fuga(32);
    hoge = hoge + fuga;
    cout << hoge << endl;
}
