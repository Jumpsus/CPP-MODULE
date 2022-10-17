#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Point::Point( Fixed const x_in, Fixed const y_in ):x(x_in), y(y_in){ // invoking initialization list

}

Point::Point (float const x, float const y):x(Fixed(x)), y (Fixed(y)){
    
}

Point::Point( void ){
    Fixed const x_in(0);
    Fixed const y_in(0);
    Point(x_in, y_in);
}

Point::Point( Point const &p ):x(p.getX()), y(p.getY()){

}

Point::~Point( void ){

}

Point   const &Point::operator=(Point const &p){
    std::cout << "Cannot copy from p (x):" << p.getX() << " (y):" << p.getY() << std::endl;
    return (*this);
}

Fixed   Point::getX() const{
    return (this->x);
}

Fixed   Point::getY() const{
    return (this->y);
}

bool    Point::isBetween(Point const start, Point const end) const{
    
    if (this->x > Fixed::max(start.getX(), end.getX()))
        return false;
    if (this->x < Fixed::min(start.getX(), end.getX()))
        return false;
    if (this->y > Fixed::max(start.getY(), end.getY()))
        return false;
    if (this->y < Fixed::min(start.getY(), end.getY()))
        return false;
    return (true);
}