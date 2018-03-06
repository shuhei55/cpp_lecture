#include <iostream>

void check(auto a)
{
    try {
        throw a;
    } catch (int&) {
        std::cout << "int" << std::endl;
    } catch (float&) {
        std::cout << "float" << std::endl;
    } catch (double&) {
        std::cout << "double" << std::endl;
    } catch (char&) {
        std::cout << "char" << std::endl;
    } catch (...) {
        std::cout << "exception" << std::endl;
    }
}

int main()
{
    std::cout << "0.0 ";
    check(0.0);
    std::cout << "0 ";
    check(0);
    std::cout << "0.0f ";
    check(0.0f);
    std::cout << "'0' ";
    check('0');
    std::cout << "hello ";
    check("hello");
}
