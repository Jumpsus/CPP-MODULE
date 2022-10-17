#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point{
    public:
        Point( void );
        Point( Fixed const x, Fixed const y );
        Point( float const x, float const y);
        Point( Point const &p );

        ~Point( void );
        Point  const &operator=(Point const &p);

        Fixed   getX() const;
        Fixed   getY() const;

        bool    isBetween(Point const start, Point const end) const;

    private:
        Fixed   const x;
        Fixed   const y;
};

bool    bsp (Point const a, Point const b, Point const c, Point const point);
#endif