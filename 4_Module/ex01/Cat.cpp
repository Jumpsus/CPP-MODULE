#include "Cat.hpp"

Cat::Cat() : Animal("cat"){
    std::cout << "Create Default constructor Cat" << std::endl;
    this->brain = new Brain();
}

Cat::~Cat(){
    delete(this->brain);
    std::cout << "Destroy Cat (Noooooo !!)" << std::endl;
}

Cat::Cat(Cat const &cat): Animal(cat.type){
    std::cout << "Copy constructor Cat" <<std::endl;
    this->brain = new Brain();
    *(this->brain) = *(cat.brain);
}

Cat &Cat::operator=(Cat const &cat){
    std::cout << "Use copy operator Cat" <<std::endl;
    this->type = cat.type;
    *(this->brain) = *(cat.brain);
    return (*this);
}

Animal &Cat::operator=(Animal const &animal){
    std::cout << "Use copy operator Cat" <<std::endl;
    this->type = animal.getType();
    *(this->brain) = *(animal.getBrain());
    return (*this);
}

void Cat::makeSound(){
    std::cout << "Cat: Meowwwwwww~" <<std::endl;
}

std::ostream &operator<<(std::ostream &out, Cat &cat){
    out << cat.getType();
    return (out);
}

Brain *Cat::getBrain() const{
    return (this->brain);
}