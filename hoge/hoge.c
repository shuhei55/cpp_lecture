#include <boost/version.hpp>
#include <iostream>

int main()
{
    int major = BOOST_VERSION / 100000;
    int minor = BOOST_VERSION / 100 % 1000;
    int patch = BOOST_VERSION % 100;
    std::cout << "boost version " << major << "." << minor << "." << patch
              << " or " << BOOST_LIB_VERSION << std::endl;
    return 0;
}
