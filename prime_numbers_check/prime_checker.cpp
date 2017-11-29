#include <iostream>
#include <array>
#include <math.h>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    int n;
    while(true){
        cin >> n;
        clock_t start = clock();
        vector<int> a(n + 1, 1);
        for (int i = 2; i < n + 1; i++) {
            if (a.at(i) == 1) {
                for (int j = i + 1; j <= (n / i); j++) {
                    a.at(i * j) = 0;
                }
            }
        }
        clock_t end = clock();
        cout << static_cast<double>(end - start) / CLOCKS_PER_SEC << endl;
        if (a.at(n) == 1) {
            cout << "素数" << endl;
        } else {
            cout << "NOT素数" << endl;
        }
    }
}

