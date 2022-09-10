#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w){
    this->name = n;
    this->weapon = &w;
}

HumanA::~HumanA(){
    std::cout << this->name << " is destroyed" << std::endl;
}

void    HumanA::attack(){
    std::cout << this->name << " attacks with their " << (this->weapon)->getType() << std::endl;
}
