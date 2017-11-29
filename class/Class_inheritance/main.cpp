#include <iostream>
#include <vector>

using namespace std;

class AbstShape {
    public:
    virtual bool hit (float x, float y) const = 0;
};

class Rectangle : public AbstShape
{
    public:
    explicit Rectangle (double x, double y, double width, double height):x(x), y(y), width(width), height(height) {};
    bool hit (float px, float py) overide{
        return (x < px && px < (x + width)) && (y < py && (py < y + height))
    }
};

vector<AbstShape*> {
    new Rectangle(0,0,300,200)
};

int main()
{
    cout << hit.AbstShape(159, 100) << endl;
}
