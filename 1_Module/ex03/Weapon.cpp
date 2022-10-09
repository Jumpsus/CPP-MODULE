#include "Weapon.hpp"

Weapon::Weapon(){
    this->type = "unknown weapon";
    std::cout << "Weapon " << this->type << " is created" << std::endl;
}

Weapon::Weapon(std::string t){
    this->type = t;
    std::cout << "Weapon " << this->type << " is created" << std::endl;
}

Weapon::~Weapon(){
    std::cout << this->type << " was destroyed" << std::endl;
}

std::string Weapon::getType(){
    return (this->type);
}

void    Weapon::setType(std::string t){
    this->type = t;
}