#pragma once
#include <array>
#include <memory>

template <int Tate, int Yoko>
class Board
{
public:
    explicit Board(){};

    void addkoma(std::weak_ptr<AbstKoma> new_koma) {}

private:
    std::array<std::array<std::weak_ptr<AbstKoma>, Yoko>, Tate> koma;
};
