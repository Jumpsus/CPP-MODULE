#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C: public Base{
    public:
        C();
        C(const C &c);

        C &operator=(const C& c);
        ~C();
};

#endif