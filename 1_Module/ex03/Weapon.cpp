#include "Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon(std::string t){
    this->type = t;
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