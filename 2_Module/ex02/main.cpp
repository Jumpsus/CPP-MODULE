#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    {
        std::cout << "*** Mandatory Test ***" << std::endl;
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;

    }
    {
        std::cout << std::endl << "*** My Test ***" << std::endl;
        Fixed a (10.5f);
        Fixed b (5.0f);

        std::cout << "=== Starter ===" << std::endl;
        std::cout << "a = " << a.toFloat() << std::endl;
        std::cout << "b = " << b.toFloat() << std::endl;

        std::cout << std::endl << "=== Basic Operator (+ - * /) ===" << std::endl;
        std::cout << "a + b = " << a + b << std::endl;
        std::cout << "a - b = " << a - b << std::endl;
        std::cout << "a * b = " << a * b << std::endl;
        std::cout << "a / b = " << a / b << " (Got weird value because limit of fractional bits)"<< std::endl;

        std::cout << std::endl << "=== Compare Operator (== != < >) ===" << std::endl;
        std::cout << "a == b is " << std::boolalpha << (a == b) << std::endl;
        std::cout << "a != b is " << std::boolalpha << (a != b) << std::endl;
        std::cout << "a > b is " << std::boolalpha << (a > b) << std::endl;
        std::cout << "a < b is " << std::boolalpha << (a < b) << std::endl;
        std::cout << "a >= b is " << std::boolalpha << (a >= b) << std::endl;
        std::cout << "a <= b is " << std::boolalpha << (a <= b) << std::endl;

        std::cout << std::endl << "=== Pre / Post Incremect / Decrement Operator (x++, ++x, --x, x--) ===" << std::endl;
        std::cout << "Result of ++a = " << ++a << std::endl;
        std::cout << "Result of a++ = " << a++ << std::endl;
        std::cout << "a After a++ " << a << std::endl;
        std::cout << "Result of --a = " << --a << std::endl;
        std::cout << "Result of a-- = " << a-- << std::endl;
        std::cout << "a After a-- " << a << std::endl;

        std::cout << std::endl << "=== Static Function for min / max ===" << std::endl;
        std::cout << "Max between a and b is " << Fixed::max( a, b ) << std::endl;
        std::cout << "Min between a and b is " << Fixed::min( a, b ) << std::endl;

        return 0;
    }
}
