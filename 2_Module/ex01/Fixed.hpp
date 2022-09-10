#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
    private:
        int                 value;
        static const int    fractional = 8;
    public:
        Fixed();
        Fixed(int const value);
        Fixed(float const value);
        Fixed(Fixed const  &f);

        Fixed   &operator=(Fixed const &f);
        
        ~Fixed();
        int     toInt( void ) const;
        float   toFloat( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

std::ostream &operator<<( std::ostream &output, const Fixed &f);

#endif