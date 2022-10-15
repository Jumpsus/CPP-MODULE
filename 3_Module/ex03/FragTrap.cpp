#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "Create Default FragTrap." << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name){
    std::cout << "Create FragTrap name : " << this->getName() << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDamage(30);
}

FragTrap::~FragTrap(){
    std::cout << "Destroy FragTrap name : " << this->getName() << std::endl;
}

FragTrap::FragTrap(FragTrap const &f) : ClapTrap(f.getName()){
    this->setName(f.getName());
    this->setAttackDamage(f.getAttackDamage());
    this->setEnergyPoint(f.getEnergyPoint());
    this->setHitPoint(f.getHitPoint());
}

FragTrap &FragTrap::operator=(FragTrap const &f){
    this->setName(f.getName());
    this->setAttackDamage(f.getAttackDamage());
    this->setEnergyPoint(f.getEnergyPoint());
    this->setHitPoint(f.getHitPoint());

    return (*this);
}

void    FragTrap::attack(std::string const &target){
    if (this->getEnergyPoint() <= 0){
        std::cout << this->getName() << " doesn't have enough Enerygy Point" << std::endl;
        return ;
    }
    if (this->getHitPoint() <= 0){
        std::cout << this->getName() << " doesn't have enough Hit Point" << std::endl;
        return ;
    }
    this->setEnergyPoint(this->getEnergyPoint() - 1);
    std::cout << "FragTrap " << this->getName() << " frags " << target << " , causing " << this->getAttackDamage() << " points of damage!" << std::endl; 
}

void    FragTrap::highFiveGuys(){
    std::cout << "FragTrap "<< this->getName() << " give you high fives." << std::endl;
}

std::ostream &operator<<(std::ostream &out, FragTrap &f){
    out << f.getName();
    return (out);
}