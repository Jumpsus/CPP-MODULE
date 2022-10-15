#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "Create Default ClapTrap." << std::endl;
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap( std::string const name ):name(name){
    std::cout << "Create ClapTrap name : " << name << std::endl;
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap name : " << name << " is Destroyed.."<< std::endl;
}

std::string ClapTrap::getName() const{
    return (this->name);
}

int     ClapTrap::getHitPoint() const{
    return (this->hitPoint);
}

int     ClapTrap::getEnergyPoint() const{
    return (this->energyPoint);
}

int     ClapTrap::getAttackDamage() const{
    return (this->attackDamage);
}

ClapTrap::ClapTrap( ClapTrap const &c ){
    std::cout << "copy ClapTrap name : " << c.getName() << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &c){
    this->name = c.getName();
    this->hitPoint = c.getHitPoint();
    this->energyPoint = c.getEnergyPoint();
    this->attackDamage = c.getAttackDamage();
    return (*this);
}

void    ClapTrap::attack(const std::string &target){
    if (this->energyPoint <= 0){
        std::cout << this->name << " doesn't have enough Enerygy Point" << std::endl;
        return ;
    }
    if (this->hitPoint <= 0){
        std::cout << this->name << " doesn't have enough Hit Point" << std::endl;
        return ;
    }
    this->energyPoint--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << " , causing " << this->attackDamage << " points of damage!" << std::endl; 
}

void    ClapTrap::takeDamage(unsigned int amount){
    std::cout << this->name << " has taken " << amount << " damage points !!" << std::endl;
    this->hitPoint = this->hitPoint - amount;
    std::cout << this->name << " currently has " << this->hitPoint << " hit points !!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (this->energyPoint <= 0){
        std::cout << this->name << " doesn't have enough Enerygy Point" << std::endl;
        return ;
    }
    if (this->hitPoint <= 0){
        std::cout << this->name << " has already been knocked out (0 Hit Point)" << std::endl;
        return ;
    }
    std::cout << this->name << " has repaired " << amount << " hit points !!" << std::endl;
    this->hitPoint = this->hitPoint + amount;
    this->energyPoint--;
    std::cout << this->name << " currently has " << this->hitPoint << " hit points !!" << std::endl;
    std::cout << this->name << " currently has " << this->energyPoint << " energy points !!" << std::endl;
}

void ClapTrap::Showinfo(ClapTrap const &c){
    std::cout << c.getName() << " has " << c.getHitPoint() << " hit points and " << c.getEnergyPoint() << " energy points left" << std::endl;
}

std::ostream &operator<<(std::ostream &out, ClapTrap &c){
    out << c.getName();
    return (out);
}