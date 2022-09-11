#include "A.hpp"

A::A(){
    std::cout << "Default constructor A" << std::endl;
}

A::A(A const &a):Base(){
    *this = a;
    std::cout << "Default Copy Constructor A" << std::endl;
}

A &A::operator=(A const &a){
    std::cout << "Assigned Copy Constructor A" << std::endl;
    if (this == &a){
        return (*this);
    }
    return (*this);
}

A::~A(){
    std::cout << "Destructor A" << std::endl;
}