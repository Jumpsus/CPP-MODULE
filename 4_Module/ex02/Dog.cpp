#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Create Default constructor Dog" << std::endl;
    this->type = "dog";
    this->brain = new Brain();
}

Dog::~Dog(){
    delete (this->brain);
    std::cout << "Destroy Dog (T_T)" << std::endl;
}

Dog::Dog(Dog const &dog): Animal(){
    std::cout << "Copy constructor Dog" <<std::endl;
    this->type = dog.getType(); // actually this don't need to use getType
    this->brain = new Brain();
    *(this->brain) = *(dog.brain);
}

Dog &Dog::operator=(Dog const &dog){
    std::cout << "Use copy operator Dog" <<std::endl;
    this->type = dog.getType(); // actually this don't need to use getType
    *(this->brain) = *(dog.brain);
    return (*this);
}

Animal &Dog::operator=(Animal const &animal){
    std::cout << "Use copy operator Cat" <<std::endl;
    this->type = animal.getType();
    *(this->brain) = *(animal.getBrain());
    return (*this);
}

void    Dog::makeSound(){
    std::cout << "Dog: Barkkkkkkkkk!!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Dog &dog){
    out << dog.getType();
    return (out);
}

Brain   *Dog::getBrain() const{
    return (this->brain);
}