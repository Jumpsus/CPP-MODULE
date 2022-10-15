#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Create Default constructor Cat" << std::endl;
    this->type = "cat";
}

Cat::~Cat(){
    std::cout << "Destroy Cat (Noooooo !!)" << std::endl;
}

Cat::Cat(Cat const &cat): Animal(){
    std::cout << "Copy constructor Cat" <<std::endl;
    this->type = cat.type;
}

Cat &Cat::operator=(Cat const &cat){
    std::cout << "Use copy operator Cat" <<std::endl;
    this->type = cat.type;
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Cat: Meowwwwwww~" <<std::endl;
}

std::ostream &operator<<(std::ostream &out, Cat &cat){
    out << cat.getType();
    return (out);
}