#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base{
    public:
        Base();
        Base(Base const &base);

        Base &operator=(Base const &base);
        virtual ~Base();
};

std::ostream &operator<<(std::ostream &out, Base const &base);

#endif