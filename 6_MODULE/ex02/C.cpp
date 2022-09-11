#include "C.hpp"

C::C(){
    std::cout << "Default constructor C" << std::endl;
}

C::C(C const &c):Base(){
    *this = c;
    std::cout << "Default Copy Constructor C" << std::endl;
}

C &C::operator=(C const &c){
    std::cout << "Assigned Copy Constructor C" << std::endl;
    if (this == &c){
        return (*this);
    }
    return (*this);
}

C::~C(){
    std::cout << "Destructor C" << std::endl;
}
