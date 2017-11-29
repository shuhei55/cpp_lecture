#include <iostream>
#include <array>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    array<int, 12> e;
    for (int i = 0; i < 12; i++) {
        cin >> e.at(i);
    }
    sort(e.begin(), e.end());
    if (e.at(0) == e.at(3) && e.at(4) == e.at(7) && e.at(8) == e.at(11)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
    /*array<int, 12> check;
    for (int i = 0; i < 12; i++) {
        for (int j : e) {
            if (e.at(i) == j) {
                check.at(i) += 1;
            }
        }
        if (check.at(i) >= 4) {
        } else {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;*/
}
