#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "Create Default constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type): type(type){
    std::cout << "Create constructor WrongAnimal type: " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &animal){
    std::cout << "Create copy constructor" << std::endl;
    this->type = animal.type;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Destroy WrongAnimal type: " << this->type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal){
    std::cout << "Use operator copy (=)" << std::endl;
    this->type = animal.type;
    return (*this);
}

std::string WrongAnimal::getType() const{
    return (this->type);
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal: ASDFJKL:!@#" << std::endl; 
}

std::ostream &operator<<(std::ostream &out, WrongAnimal &animal){
    out << animal.getType();
    return (out);
}