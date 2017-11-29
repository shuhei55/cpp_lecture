#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >>a>>b>>c>>d;
    if (a == b) {
        if (a != c && a != d) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    } else if (a == c) {
        if (a != d) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    } else if (a == d) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
