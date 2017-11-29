#include <iostream>
#include <array>
using namespace std;

int main()
{
    int a;
    while(true){
        cin >> a;
        cout<< (a<5 ? "Happy" : a > 6 ? "angry" : "OK") << endl;
    }
}
