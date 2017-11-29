#include <iostream>
#include <array>
#include <string>
#include "head.hpp"
#include <math.h>

using namespace std;

array<array<int, 8>, 8> position = {{
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,1,2,0,0,0},
    {0,0,0,2,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
}};

void play()
{
    cout << "  ０ １ ２ ３ ４ ５ ６ ７" << endl;
    for(int y = 0; y < 8; y++){
        cout << "  ";
        for(int x = 0; x < 8; x++){
            cout << "---";
        }
        cout << endl;
        cout << y;
        for(int x = 0; x < 8; x++){
            cout << "|";
            each(x, y);
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for(int y = 0; y < 8; y++){
        cout << "---";
    }
    cout << endl;
}

void each(int x, int y)
{
    if (position.at(y).at(x) == 0) {
        cout << "  ";
    } else if (position.at(y).at(x) == 1) {
        cout << "１";
    } else {
        cout << "２";
    }
}

void change_p1()
{
    cout << "P1の番です" << endl;
    int posi_x;
    int posi_y;
    cin >> posi_x >> posi_y;
    if (0 <= posi_x && posi_x <= 7 && 0 <= posi_y && posi_y <= 7){
        check(posi_x, posi_y, 2, 1);
    } else {
        cout << "違うよ！" << endl;
    }
}

void change_p2()
{
    cout << "P2の番です" << endl;
    int posi_x;
    int posi_y;
    cin >> posi_x >> posi_y;
    if (0 <= posi_x && posi_x <= 7 && 0 <= posi_y && posi_y <= 7){
        check(posi_x, posi_y, 1, 2);
    } else {
        cout << "違うよ！" << endl;
    }
}


void check(int x, int y, int n, int k)
{
    int check = 0;
    if (position.at(y).at(x) == 0) {
        check_0(check, x, y, n, k);
        check_1(check, x, y, n, k);
        check_2(check, x, y, n, k);
        check_3(check, x, y, n, k);
        check_4(check, x, y, n, k);
        check_5(check, x, y, n, k);
        check_6(check, x, y, n, k);
        check_7(check, x, y, n, k);
        if (check == 1) {
            position.at(y).at(x) = k;
            gamemode *= -1;
        } else {
            cout << "そこは置けないよ！"<<endl;
        }
    } else {
        cout << "そこは置けないよ" << endl;
    }

}

void check_0(int &c, int x, int y, int n, int k)
{
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

void check_1(int &c, int x, int y, int n, int k)
{
    if (y == 0 || x == 7) {
    } else {
        if (position.at(y - 1).at(x + 1) == k) {
        } else {
            for (int i = 1; i <= max(y, (7 - x)); i++) {
                if (position.at(y - i).at(x + i) == n) {
                    continue;
                } else if (position.at(y - i).at(x + i) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y - j).at(x + j) = k;
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

void check_2(int &c, int x, int y, int n, int k)
{
    if (x == 7) {
    } else {
        if (position.at(y).at(x + 1) == k) {
        } else {
            for (int i = 1; i <= (7 - x); i++) {
                if (position.at(y).at(x + i) == n) {
                    continue;
                } else if (position.at(y).at(x + i) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y).at(x + j) = k;
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

void check_3(int &c, int x, int y, int n, int k)
{
    if (y == 7 || x == 7) {
    } else {
        if (position.at(y + 1).at(x + 1) == k) {
        } else {
            for (int i = 1; i <= max((7 - y), (7 - x)); i++) {
                if (position.at(y + i).at(x + i) == n) {
                    continue;
                } else if (position.at(y + i).at(x + i) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y + j).at(x + j) = k;
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

void check_4(int &c, int x, int y, int n, int k)
{
    if (y == 7) {
    } else {
        if (position.at(y + 1).at(x) == k) {
        } else {
            for (int i = 1; i <= 7 - y; i++) {
                if (position.at(y + i).at(x) == n) {
                    continue;
                } else if (position.at(y + i).at(x) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y + j).at(x) = k;
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

void check_5(int &c, int x, int y, int n, int k)
{
    if (y == 7 || x == 0) {
    } else {
        if (position.at(y + 1).at(x - 1) == k) {
        } else {
            for (int i = 1; i <= max((7 - y), x); i++) {
                if (position.at(y + i).at(x - i) == n) {
                    continue;
                } else if (position.at(y + i).at(x - i) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y + j).at(x - j) = k;
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

void check_6(int &c, int x, int y, int n, int k)
{
    if (x == 0) {
    } else {
        if (position.at(y).at(x - 1) == k) {
        } else {
            for (int i = 1; i <= x; i++) {
                if (position.at(y).at(x - i) == n) {
                    continue;
                } else if (position.at(y).at(x - i) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y).at(x - j) = k;
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

void check_7(int &c, int x, int y, int n, int k)
{
    if (x == 0 || y == 0) {
    } else {
        if (position.at(y - 1).at(x - 1) == k) {
        } else {
            for (int i = 1; i <= max(x, y); i++) {
                if (position.at(y - i).at(x - i) == n) {
                    continue;
                } else if (position.at(y - i).at(x - i) == k) {
                    for (int j = 1; j <= i; j++) {
                        position.at(y - j).at(x - j) = k;
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
