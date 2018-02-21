#include <iostream>

#include <vector>

#include <memory>



class AbstShape{

public:

    //pure virtual function

    virtual bool hit(float x, float y) const = 0; 

};

class Rectangle: public AbstShape

{

public:

    Rectangle(float x, float y, float width, float height)

        : m_x(x), m_y(y), m_width(width), m_height(height) {}

    bool hit(float x, float y) const override {

        return (m_x <= x) && (x <= m_x + m_width)

                && (m_y <= y) && ( y <= m_y + m_height);

    }

private:

    float m_x, m_y, m_width, m_height;

};



class Circle: public AbstShape

{

public:

    Circle(float x, float y, float r)

        : m_x(x), m_y(y), m_r(r) {}

    bool hit(float x, float y) const override {

        return (x - m_x) * (x - m_x) + (y - m_y) * (y - m_y)

                <= m_r * m_r;

    }

private:

    float m_x, m_y, m_r;

};



class Line: public AbstShape

{

public:

    Line(float a, float b, float c, float width)

        : m_a(a), m_b(b), m_c(c), m_width(width) {}

    bool hit(float x, float y) const override{

        float d = m_a * x + m_b * y - m_c;

        return d * d / (m_a * m_a + m_b * m_b) <= m_width * m_width;

    }

private:

    float m_a, m_b, m_c, m_width;

};



using namespace std;



vector<AbstShape*> g_shapes 

    = {new Rectangle(1000, 500, 500, 1000), 

       new Rectangle(1000, -1500, 500, 1000),

       new Circle(2000, 0, 1000),

       new Line(1, 1, 5000, 25)}; 



bool hit(float x, float y){

    for(AbstShape* shape: g_shapes){

        if(shape->hit(x, y)) return true;    

    }

    return false;

}



int main(){

    cout << hit(0, 0) << endl;          //0

    cout << hit(1500, 0) << endl;       //1 

    cout << hit(1010, 400) << endl;     //0

    cout << hit(1010, 600) << endl;     //1

    cout << hit(1400, -600) << endl;    //1

    cout << hit(5000, 25) << endl;      //1

    cout << hit(5000, 50) << endl;     //0

    cout << hit(49, 0) << endl;       //1

    return 0;

}
