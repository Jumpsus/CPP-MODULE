#include "Base.hpp"

Base::Base(){
    std::cout << "Default constructor Base" << std::endl;
}

Base::Base(Base const &base){
    *this = base;
    std::cout << "Default Copy Constructor Base" << std::endl;
}

Base &Base::operator=(Base const &base){
    std::cout << "Assigned Copy Constructor Base" << std::endl;
    if (this == &base){
        return (*this);
    }
    return (*this);
}

Base::~Base(){
    std::cout << "Destructor Base" << std::endl;
}
