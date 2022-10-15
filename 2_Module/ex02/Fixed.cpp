#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
    // std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(int const value){
    this->value = value << this->fractional;
}

int Fixed::toInt( void ) const {
    return (this->value >> this->fractional);
}

Fixed::Fixed(float const value) {
    /* convert floating point to fixed point needed to 
       do followind equation: roundf(float * 2^(fix_fractional)) 
       roundf is for excession bit that came from mutiplying */
    this->value = roundf(value * pow(2, this->fractional));
}

float Fixed::toFloat( void ) const {
    return ((float) this->value / pow(2, this->fractional));
}

Fixed::Fixed(Fixed const &f){
    // std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed(){
    // std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &f){
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f){
        this->value = f.getRawBits();
    }
    return (*this);
}

int     Fixed::getRawBits( void ) const{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void    Fixed::setRawBits( int const raw ){
    // std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

std::ostream &operator<<( std::ostream &output, const Fixed &f){
    output << f.toFloat();
    return (output);
}

bool Fixed::operator!=(Fixed const &f){ return (this->getRawBits() != f.getRawBits()); }
bool Fixed::operator==(Fixed const &f){ return (this->getRawBits() == f.getRawBits()); }
bool Fixed::operator>(Fixed const &f){ return (this->getRawBits() > f.getRawBits()); }
bool Fixed::operator<(Fixed const &f){ return (this->getRawBits() < f.getRawBits()); }
bool Fixed::operator>=(Fixed const &f){ return (this->getRawBits() >= f.getRawBits()); }
bool Fixed::operator<=(Fixed const &f){ return (this->getRawBits() <= f.getRawBits()); }

Fixed   Fixed::operator+(Fixed const &f){
    Fixed   result;

    result.setRawBits(this->getRawBits() + f.getRawBits());
    return (result);
}

Fixed   Fixed::operator-(Fixed const &f){
    Fixed   result;

    result.setRawBits(this->getRawBits() - f.getRawBits());
    return (result);
}

Fixed   Fixed::operator*(Fixed const &f){
    Fixed   result(this->toFloat() * f.toFloat());

    return (result);
}

Fixed   Fixed::operator/(Fixed const &f){
    float   res = this->toFloat() / f.toFloat();
    Fixed   result(res);

    return (result);
}

Fixed   Fixed::operator++( void ){
    this->value++;
    return (*this);
}

Fixed   Fixed::operator++( int ){
    Fixed   result(*this);
    this->value++;
    return (result);
}

Fixed   Fixed::operator--( void ){
    this->value--;
    return (*this);
}

Fixed   Fixed::operator--( int ){
    Fixed   result(*this);
    this->value--;
    return (result);
}


Fixed   &Fixed::min(Fixed &f1, Fixed &f2){
    if (f1.getRawBits() < f2.getRawBits()){
        return (f1);
    }
    return (f2);
}

Fixed   &Fixed::max(Fixed &f1, Fixed &f2){
    if (f1.getRawBits() > f2.getRawBits()){
        return (f1);
    }
    return (f2);
}

Fixed   const &Fixed::min(const Fixed &f1, const Fixed &f2){
    if (f1.getRawBits() < f2.getRawBits()){
        return (f1);
    }
    return (f2);
}

Fixed   const &Fixed::max(const Fixed &f1, const Fixed &f2){
    if (f1.getRawBits() > f2.getRawBits()){
        return (f1);
    }
    return (f2);
}
