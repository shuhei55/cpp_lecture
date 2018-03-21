#include <iostream>

using namespace std;

int main()
{
    float a = 4.6f;
    int i = 1;
    float& g = reinterpret_cast<float&>(i);
    int& b = reinterpret_cast<int&>(a);
    cout << a << endl;
    cout << b << endl;
    cout << i << endl;
    cout << g << endl;
}
