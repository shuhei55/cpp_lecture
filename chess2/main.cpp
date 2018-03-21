//#include "lib/include/box.hpp"
#include "lib/include/pone.hpp"
#include <iostream>

Pone pone{0, 0, 0};

int main()
{
    std::cout << pone.return_tate() << std::endl;
    std::cout << pone.return_yoko() << std::endl;
    pone.removed();
    std::cout << pone.return_tate() << std::endl;
    std::cout << pone.return_yoko() << std::endl;
    pone.change_position(4, 5);
    std::cout << pone.return_tate() << std::endl;
    std::cout << pone.return_yoko() << std::endl;
}
