#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Create Default constructor Dog" << std::endl;
    this->type = "dog";
}

Dog::~Dog(){
    std::cout << "Destroy Dog (T_T)" << std::endl;
}

Dog::Dog(Dog const &dog): Animal(){
    std::cout << "Copy constructor Dog" <<std::endl;
    this->type = dog.getType();
}

Dog &Dog::operator=(Dog const &dog){
    std::cout << "Use copy operator Dog" <<std::endl;
    this->type = dog.getType();
    return (*this);
}

void    Dog::makeSound(){
    std::cout << "Dog: Barkkkkkkkkk!!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Dog &dog){
    out << dog.getType();
    return (out);
}