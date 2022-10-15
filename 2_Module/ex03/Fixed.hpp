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
        ~Fixed();

        Fixed &operator=(Fixed const &f);
        bool    operator>(Fixed const &f);
        bool    operator<(Fixed const &f);
        bool    operator>=(Fixed const &f);
        bool    operator<=(Fixed const &f);
        bool    operator==(Fixed const &f);
        bool    operator!=(Fixed const &f);
        Fixed   operator+(Fixed const &f);
        Fixed   operator-(Fixed const &f);
        Fixed   operator*(Fixed const &f);
        Fixed   operator/(Fixed const &f);

        bool    operator>(Fixed const &f) const;
        bool    operator<(Fixed const &f) const;
        bool    operator>=(Fixed const &f) const;
        bool    operator<=(Fixed const &f) const;
        bool    operator==(Fixed const &f) const;
        bool    operator!=(Fixed const &f) const;
        
        Fixed   const   operator+(Fixed const &f) const;
        Fixed   const   operator-(Fixed const &f) const;
        Fixed   const   operator*(Fixed const &f) const;
        Fixed   const   operator/(Fixed const &f) const;

        Fixed   operator++(void); // pre-increment
        Fixed   operator++(int); // post-increment
        Fixed   operator--(void); // pre-decrement
        Fixed   operator--(int); // post-decrement

        static Fixed        &min(Fixed &f1, Fixed &f2);
        static Fixed const  &min(const Fixed &f1, const Fixed &f2);// todo
        static Fixed        &max(Fixed &f1, Fixed &f2);
        static Fixed const  &max(const Fixed &f1, const Fixed &f2);// todo
        int     toInt( void ) const;
        float   toFloat( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

std::ostream &operator<<( std::ostream &output, const Fixed &f);

#endif