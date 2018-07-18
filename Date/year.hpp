#pragma once
#include <iostream>
class Year
{
private:
    int m_y = 0;

public:
    Year() = default;
    Year(int year) : m_y(year) {}

    Year operator+(Year y) const
    {
        return Year{m_y + y.m_y};
    }

    int return_year() const
    {
        return m_y;
    }
};

std::ostream& operator<<(std::ostream& s, const Year& y)
{
    return s << y.return_year();
}
