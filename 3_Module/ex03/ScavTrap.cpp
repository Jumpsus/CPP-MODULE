#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "Create Default ScavTrap." << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name){
    std::cout << "Create ScavTrap name : " << this->getName() << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(){
    std::cout << "Destroy ScavTrap name : " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &s) : ClapTrap(s.getName()){
    this->setName(s.getName());
    this->setAttackDamage(s.getAttackDamage());
    this->setEnergyPoint(s.getEnergyPoint());
    this->setHitPoint(s.getHitPoint());
}

ScavTrap &ScavTrap::operator=(ScavTrap const &s){
    this->setName(s.getName());
    this->setAttackDamage(s.getAttackDamage());
    this->setEnergyPoint(s.getEnergyPoint());
    this->setHitPoint(s.getHitPoint());

    return (*this);
}

void    ScavTrap::attack(std::string const &target){
    if (this->getEnergyPoint() <= 0){
        std::cout << this->getName() << " doesn't have enough Enerygy Point" << std::endl;
        return ;
    }
    if (this->getHitPoint() <= 0){
        std::cout << this->getName() << " doesn't have enough Hit Point" << std::endl;
        return ;
    }
    this->setEnergyPoint(this->getEnergyPoint() - 1);
    std::cout << "ScavTrap " << this->getName() << " scavs " << target << " , causing " << this->getAttackDamage() << " points of damage!" << std::endl; 
}

void    ScavTrap::guardGate(){
    std::cout << "ScavTrap "<< this->getName() << " is now in Gate keeper mode." << std::endl;
}

std::ostream &operator<<(std::ostream &out, ScavTrap &s){
    out << s.getName();
    return (out);
}