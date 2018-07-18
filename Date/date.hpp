#include <iostream>
#include <string>

class Date
{
    int y;  //西暦年
    int m;  //月
    int d;  //日

    static int dmax[];
    static int days_of_year(int year);              //year年の日数
    static int days_of_month(int year, int month);  //year年month月の日数

public:
    static bool leap_year(int year)
    {
        return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }
    explicit Date() : y(2000), m(1), d(1) {}
    explicit Date(int yy) : y(yy), m(1), d(1) {}
    explicit Date(int yy, int mm = 1, int dd = 1) : y(yy), m(mm), d(dd) {}
    bool leap_year() const { return leap_year(y); }

    int year() const { return y; }
    int month() const { return m; }
    int day() const { return d; }

    void set(int yy, int mm, int dd) { y = yy, m = mm, d = dd; }
    void set(int yy) { y = yy; }
    void set(int mm) { m = mm; }
    void set(int dd) { d = dd; }
};
