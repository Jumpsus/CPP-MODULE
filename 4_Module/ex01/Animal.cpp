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

Animal &Animal::operator=(Animal const &animal){
    std::cout << "Animal Use operator copy (=)" << std::endl;
    this->type = animal.type;
    return (*this);
}

std::string Animal::getType() const{
    return (this->type);
}

void Animal::makeSound(){
    std::cout << "Animal: ASDFJKL:!@#" << std::endl; 
}

std::ostream &operator<<(std::ostream &out, Animal &animal){
    out << animal.getType();
    return (out);
}

Brain *Animal::getBrain() const{
    std::cout << "Normal Animal doesn't has brain" << std::endl;
    return (NULL);
}