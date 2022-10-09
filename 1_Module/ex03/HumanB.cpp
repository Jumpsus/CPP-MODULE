#include "HumanB.hpp"

HumanB::HumanB(std::string n, Weapon &w):name(n), weapon(&w){
    std::cout << this->name << " is created" << std::endl;
}

HumanB::HumanB(std::string n):name(n), weapon(NULL){
    std::cout << this->name << " is created" << std::endl;
}

HumanB::~HumanB(){
    std::cout << this->name << " is destroyed" << std::endl; 
}

void    HumanB::setWeapon(Weapon &w){
    this->weapon = &w;
}

void    HumanB::attack(){
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() <<std::endl;
    else
        std::cout << this->name << " has no weapon" << std::endl;
}
