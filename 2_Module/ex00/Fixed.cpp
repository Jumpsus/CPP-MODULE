#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->integer = 0;
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
        this->integer = f.getRawBits();
    }
    return (*this);
}

int     Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->integer);
}

void    Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    this->integer = raw;
}