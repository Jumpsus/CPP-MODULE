#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
    private:
        int                 integer;
        static const int    fractional = 8;
    public:
        Fixed();
        Fixed(Fixed const  &f);
        Fixed &operator=(Fixed const &f);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif