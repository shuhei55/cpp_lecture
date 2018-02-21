#include <iostream>
#include <vector>

using namespace std;

class AbstShape {
   public:
    virtual bool hit(double x, double y) const = 0;
};

class Rectangle : public AbstShape {
   public:
    explicit Rectangle(double x, double y, double width, double height)
        : m_x(x), m_y(y), m_width(width), m_height(height) {}
    bool hit(double x, double y) const override {
        return (m_x < x && x < (m_x + m_width)) &&
               (m_y < y && (y < m_y + m_height));
    }

   private:
    double m_x, m_y, m_width, m_height;
};

class Circle : public AbstShape {
   public:
    explicit Circle(double x, double y, double r) : m_x(x), m_y(y), m_r(r) {}
    bool hit(double x, double y) const override {
        return ((m_x - x) * (m_x - x) + (m_y - y) * (m_y - y) <= m_r * m_r);
    }

   private:
    double m_x, m_y, m_r;
};

vector<AbstShape*> shapes  //継承の時はポインタでやらなきゃできない
    = {new Rectangle(0, 0, 300, 200), new Circle(0, 0, 200)};

bool hit(double x, double y) {
    for (AbstShape* shape : shapes) {
        if (shape->hit(x, y)) return true;  //なんで"->"？  ーーポインタだから
    }
    return false;
}

int main() { cout << hit(159, 100) << endl; }
