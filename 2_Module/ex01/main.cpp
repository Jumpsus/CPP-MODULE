#include "Fixed.hpp"
#include <iostream>
#include <bitset>


int main( void ) {
    
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << std::endl << "=== Start Value ===" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << std::endl << "=== Raw Value ===" << std::endl;
    std::cout << "a " << std::bitset<32>(a.getRawBits()) << std::endl;
    std::cout << "b " << std::bitset<32>(b.getRawBits()) << std::endl;
    std::cout << "c " << std::bitset<32>(c.getRawBits()) << std::endl;
    std::cout << "d " << std::bitset<32>(d.getRawBits()) << std::endl;

    std::cout << std::endl << "=== Integer Value ===" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << std::endl << "=== Float Value ===" << std::endl;
    std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
    std::cout << "c is " << c.toFloat() << " as float" << std::endl;
    std::cout << "d is " << d.toFloat() << " as float" << std::endl << std::endl;

    return 0;
}
