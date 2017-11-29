#include <iostream>

using namespace std;

template<typename T = double>
struct Vector{
    T x, y;
    
    Vector<T> operator+(const Vector<T>& a){
        return {x+a.x, y+a.y};
    }
    double operator*(const Vector<T>& a){
        return x*a.x + y*a.y;
    }

};

int main(){
    Vector<T> a = {3.4, 6.2};
    Vector<T> b = {5.6, 2.7};
    Vector<T> c = a + b;
    cout << c.x << " " << c.y << " " << a * b << endl;
    
}
