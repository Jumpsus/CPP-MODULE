#include "B.hpp"

B::B(){
    std::cout << "Default constructor B" << std::endl;
}

B::B(B const &b):Base(){
    *this = b;
    std::cout << "Default Copy Constructor B" << std::endl;
}

B &B::operator=(B const &b){
    std::cout << "Assigned Copy Constructor B" << std::endl;
    if (this == &b){
        return (*this);
    }
    return (*this);
}

B::~B(){
    std::cout << "Destructor B" << std::endl;
}
