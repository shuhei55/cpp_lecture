#include "init/init.hpp"
#include <iostream>
#include "init/ui.hpp"

int main()
{
    init();

    std::cout << AbstKoma::position.at(0).at(4)->returnID() << std::endl;
    std::cout << AbstKoma::position.at(1).at(4)->returnID() << std::endl;
    change(0, 4, 1, 4);
    std::cout << AbstKoma::position.at(1).at(4)->returnID() << std::endl;
}
