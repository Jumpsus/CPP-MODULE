#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
    Point const a( Fixed (0), Fixed (0));
    Point const b( Fixed (0), Fixed (10));
    Point const c( Fixed (20), Fixed (0));

    Point const point(Fixed (20), Fixed (1));

    std::cout << bsp(a,b,c,point) << std::endl;
    return 0;
}
