#include "HumanB.hpp"

HumanB::HumanB(std::string n){
    this->name = n;
    this->weapon = NULL;
}

HumanB::~HumanB(){
    std::cout << this->name << " is destroyed" << std::endl; 
}

void    HumanB::setWeapon(Weapon &w){
    this->weapon = &w;
}

void    HumanB::attack(){
    if (this->weapon != NULL)
        std::cout << this->name << " attacks with their " << this->weapon->getType() <<std::endl;
    else
        std::cout << this->name << " has no weapon" << std::endl;
}
