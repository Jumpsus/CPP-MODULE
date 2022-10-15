#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "Create Default constructor WrongCat" << std::endl;
    this->type = "cat";
}

WrongCat::~WrongCat(){
    std::cout << "Destroy WrongCat (Noooooo !!)" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cat): WrongAnimal(){
    std::cout << "Copy constructor Cat" <<std::endl;
    this->type = cat.type;
}

WrongCat &WrongCat::operator=(WrongCat const &cat){
    std::cout << "Use copy operator WrongCat" <<std::endl;
    this->type = cat.type;
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat: Meowwwwwww~" <<std::endl;
}

std::ostream &operator<<(std::ostream &out, WrongCat &cat){
    out << cat.getType();
    return (out);
}