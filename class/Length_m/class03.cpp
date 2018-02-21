#include <iostream>
#include <array>

using namespace std;

struct Length_mm;

struct Length_m {
    Length_m() = default;

    Length_m(double len) : value(len) {}

    // Length_m(Length_mm rhs);

    // operator Length_mm() const;

    Length_m operator+(Length_m rhs) const {
        return Length_m{value + rhs.value};
    }

    Length_m operator-(Length_m rhs) { return Length_m{value - rhs.value}; }

    Length_m operator*(double rhs) const { return Length_m{value * rhs}; }

    Length_m operator/(double rhs) const { return Length_m{value / rhs}; }

    double revalue() const { return value; }

   private:
    double value;
};

Length_m operator*(double lhs, Length_m rhs) {
    return Length_m{lhs * rhs.Length_m::revalue()};
}

struct Length_mm {
    Length_mm() = default;

    Length_mm(double len) : value(len) {}

    // Length_mm(Length_m rhs);

    Length_mm(Length_m len) : value(len.Length_m::revalue() * 1000) {}

    Length_mm operator+(Length_mm rhs) const {
        return Length_mm{this->value + rhs.value};
    }

    operator Length_m() const;

    double revalue() const { return value; }

   private:
    double value;
};

Length_mm operator*(double rhs, Length_mm lhs) {
    return Length_mm{rhs * lhs.Length_mm::revalue()};
}

Length_mm::operator Length_m() const {
    return static_cast<Length_m>(Length_mm::value / 1000);
}

/*Length_mm(Length_m rhs)
{
    Length_mm::value = rhs.Length_m::revalue() * 1000;
}*/

/*Length_m(Length_mm rhs)
{
    Length_m::value = rhs.Length_mm::revalue() / 1000;
}*/

int main() {
    int n, m;
    array<Length_m, 4> a = {{{4.12}, {3.45}, {6.25}, {8.23}}};
    while (true) {
        cin >> n >> m;
        Length_m b = a.at(n) + a.at(m);
        cout << b.Length_m::revalue() << "m" << endl;
        Length_mm c = b;
        Length_m d = c;
        cout << c.Length_mm::revalue() << "mm" << endl;
        cout << d.Length_m::revalue() << "m" << endl;
    }
}
