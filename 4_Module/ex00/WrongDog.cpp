#include "WrongDog.hpp"

WrongDog::WrongDog(){
    std::cout << "Create Default constructor Wrong Dog" << std::endl;
    this->type = "dog";
}

WrongDog::~WrongDog(){
    std::cout << "Destroy Wrong Dog (T_T)" << std::endl;
}

WrongDog::WrongDog(WrongDog const &dog): WrongAnimal(){
    std::cout << "Copy constructor Wrong Dog" <<std::endl;
    this->type = dog.getType();
}

WrongDog &WrongDog::operator=(WrongDog const &dog){
    std::cout << "Use copy operator Wrong Dog" <<std::endl;
    this->type = dog.getType();
    return (*this);
}

void    WrongDog::makeSound() const{
    std::cout << "Wrong Dog: Barkkkkkkkkk!!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, WrongDog &dog){
    out << dog.getType();
    return (out);
}