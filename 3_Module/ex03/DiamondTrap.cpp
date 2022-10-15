#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
    std::cout << "Create Default DiamondTrap." << std::endl;
    this->setHitPoint(FragTrap::getHitPoint());
    this->setEnergyPoint(ScavTrap::getEnergyPoint());
    this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(std::string const name): ClapTrap(name + "_clap_name"){
    std::cout << "Create DiamondTrap name : " << name << std::endl;

    this->name = name;
    this->setHitPoint(FragTrap::getHitPoint());
    this->setEnergyPoint(ScavTrap::getEnergyPoint());
    this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap name : " << this->getName() << " is Destroyed.."<< std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &d): ClapTrap(d.getName() + "_clap_name"), FragTrap(), ScavTrap(){
    this->setName(d.getName());
    this->setHitPoint(d.getHitPoint());
    this->setEnergyPoint(d.getEnergyPoint());
    this->setAttackDamage(d.getAttackDamage());
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &d){
    ClapTrap::setName(d.getName() + "_clap_name");
    this->setName(d.getName());
    this->setHitPoint(d.getHitPoint());
    this->setEnergyPoint(d.getEnergyPoint());
    this->setAttackDamage(d.getAttackDamage());
    return (*this);
}

void    DiamondTrap::attack(std::string const &name){
    ScavTrap::attack(name);
}

void    DiamondTrap::whoAmI(){
    std::cout << "My DiamondTrap name is " << this->getName() << ", But you can call my ClapTrap name " << ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName() const{
    return (this->name);
}

void        DiamondTrap::setName(std::string name){
    this->name = name;
}

std::ostream &operator<<(std::ostream &out, DiamondTrap &d){
    out << d.getName();
    return (out);
}