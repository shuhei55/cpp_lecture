#include <iostream>

using namespace std;

int main()
{
    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long cnt = 0;
    while (true) {
        if ((5000000000 / b) <= 0)
            break;
        a += (5000000000 / b);
        b *= 2;
        cnt++;
    }
    cout << a * 21 * 10000 / 100000000 << "bitcoin" << endl;
    cout << a * 21 * 10000 << "satoshi" << endl;
    cout << cnt * 21 * 10000 / 6 / 24 / 365 << "年" << endl;
}
