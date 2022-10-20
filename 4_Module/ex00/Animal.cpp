#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Create Default constructor Animal" << std::endl;
}

Animal::Animal(std::string const &type): type(type){
    std::cout << "Create constructor Animal type: " << this->type << std::endl;
}

Animal::Animal(Animal &animal){
    std::cout << "Create copy constructor" << std::endl;
    this->type = animal.type;
}

Animal::~Animal(){
    std::cout << "Destroy Animal type: " << this->type << std::endl;
}

Animal &Animal::operator=(const Animal &animal){
    std::cout << "Use operator copy (=)" << std::endl;
    this->type = animal.type;
    return (*this);
}

std::string Animal::getType() const{
    return (this->type);
}

void Animal::makeSound() const{
    std::cout << "Animal: ASDFJKL:!@#" << std::endl; 
}

std::ostream &operator<<(std::ostream &out, Animal &animal){
    out << animal.getType();
    return (out);
}