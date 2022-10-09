#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w):name(n), weapon(w){
    std::cout << this->name << " is created" << std::endl;
}

HumanA::~HumanA(){
    std::cout << this->name << " is destroyed" << std::endl;
}

void    HumanA::attack(){
    std::cout << this->name << " attacks with their " << (this->weapon).getType() << std::endl;
}
