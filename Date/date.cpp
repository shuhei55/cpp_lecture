#include "date.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

int Date::dmax[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Date::days_of_year(int year)
{
    return 365 + leap_year(year);
}

int Date::days_of_month(int year, int month)
{
    return dmax[month - 1] + (month == 2 && leap_year(year));
}
