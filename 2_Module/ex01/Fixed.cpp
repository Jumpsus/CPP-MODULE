#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(int const value){
    std::cout << "Constructor with Integer Argument called" << std::endl;
    this->value = value << this->fractional;
}

int Fixed::toInt( void ) const {
    return (this->value >> this->fractional);
}

Fixed::Fixed(float const value) {
    /* convert floating point to fixed point needed to 
       do followind equation: roundf(float * 2^(fix_fractional)) 
       roundf is for excession bit that came from mutiplying */
    std::cout << "Constructor with Float Argument called" << std::endl;
    this->value = roundf(value * pow(2, this->fractional));
}

float Fixed::toFloat( void ) const {
    return ((float) this->value / pow(2, this->fractional));
}

Fixed::Fixed(Fixed const &f){
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &f){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f){
        this->value = f.getRawBits();
    }
    return (*this);
}

int     Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void    Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

std::ostream &operator<<( std::ostream &output, const Fixed &f){
    output << f.toFloat();
    return (output);
}