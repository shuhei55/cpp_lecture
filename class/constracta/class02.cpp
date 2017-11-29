#include <iostream>
#include <string>
#include <array>

using namespace std;

struct Rectangle
{
    Rectangle() : m_width(0), m_height(0)
    {
        cout << "デフォルトコンストラクタ" << endl;
    }
    Rectangle(double width, double height) : m_width(width), m_height(height)
    {
        cout << "普通のやつ" << endl;
    }


    Rectangle(double width) : m_width(width), m_height(10.0)
    {
        cout << "高さ10の面積" << endl;
    }

    double area ()
    {
        return m_width * m_height;
    }

    private:
    double m_width, m_height;

};

int main() 
{
    array<Rectangle, 4> a{{{4.0, 3.0}, {2.1, 4.5}, {3.4}, {}}};
    cout << a.at(0).area() << endl;
    cout << a.at(1).area() << endl;
    cout << a.at(2).area() << endl;
    cout << a.at(3).area() << endl;
}

