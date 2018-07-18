#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    float x[6] = {0.04, 0.0625, 1.0 / 9.0, 0.0625, 1.0 / 9.0, 0.04};
    float y[6] = {2.3054, 2.0518, 1.5249, 2.0611, 1.5221, 2.2747};
    float A = 0, B = 0, C = 0, D = 0, E = 0;
    for (int i = 0; i < 6; i++) {
        A += y[i] * y[i];
        B += x[i] * x[i];
        C += y[i];
        D += x[i] * y[i];
        E += x[i];
    }
    float a = (6 * D - C * E) / (6 * B - E * E);
    float b = (B * C - D * E) / (6 * B - E * E);
    cout << a << endl;
    cout << b << endl;
    printf("%f\n", a);
    printf("%f\n", b);
    float dd = sqrt((pow(1.6655 - 1.66735, 2) + pow(1.66883 - 1.66735, 2) + pow(1.66826 - 1.66735, 2) + pow(1.66646 - 1.66735, 2)) / 3);
    printf("%f\n", dd);
}
