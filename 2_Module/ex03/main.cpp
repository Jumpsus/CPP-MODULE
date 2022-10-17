#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
    {
        std::cout << "=== Out of Range Point ===" << std::endl;
        Point const a( Fixed (0), Fixed (0));
        Point const b( Fixed (0), Fixed (10));
        Point const c( Fixed (20), Fixed (0));

        Point const point(Fixed (20), Fixed (1));

        std::cout << std::boolalpha << bsp(a,b,c,point) << std::endl;   
    }
    {
        std::cout << "=== In Range Point ===" << std::endl;
        Point const a( Fixed (0), Fixed (0));
        Point const b( Fixed (5), Fixed (5));
        Point const c( Fixed (10), Fixed (0));

        Point const point(3.0f, 3.0f);

        std::cout << std::boolalpha << bsp(a,b,c,point) << std::endl;   
    }
    
    return 0;
}
