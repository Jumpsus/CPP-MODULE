#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "Create Default ClapTrap." << std::endl;
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap( std::string const name ){
    std::cout << "Create ClapTrap name : " << name << std::endl;
    this->_name = name;
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap name : " << _name << " is Destroyed.."<< std::endl;
}

std::string ClapTrap::getName() const{
    return (this->_name);
}

int     ClapTrap::getHitPoint() const{
    return (this->_hitPoint);
}

int     ClapTrap::getEnergyPoint() const{
    return (this->_energyPoint);
}

int     ClapTrap::getAttackDamage() const{
    return (this->_attackDamage);
}

void    ClapTrap::setName(const std::string &name)
{
    this->_name = name;
}

void    ClapTrap::setHitPoint(int hitPoint){
    this->_hitPoint = hitPoint;
}

void    ClapTrap::setEnergyPoint(int energyPoint){
    this->_energyPoint = energyPoint;
}

void    ClapTrap::setAttackDamage(int attackDamage){
    this->_attackDamage = attackDamage;
}

ClapTrap::ClapTrap( ClapTrap const &c ){
    std::cout << "copy ClapTrap name : " << c.getName() << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &c){
    this->_name = c.getName();
    this->_hitPoint = c.getHitPoint();
    this->_energyPoint = c.getEnergyPoint();
    this->_attackDamage = c.getAttackDamage();
    return (*this);
}

void    ClapTrap::attack(const std::string &target){
    if (this->_energyPoint <= 0){
        std::cout << this->_name << " doesn't have enough Enerygy Point" << std::endl;
        return ;
    }
    if (this->_hitPoint <= 0){
        std::cout << this->_name << " has already fainted (0 Hit Point)" << std::endl;
        return ;
    }
    this->_energyPoint--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " points of damage!" << std::endl; 
}

void    ClapTrap::takeDamage(unsigned int amount){
    std::cout << this->_name << " has taken " << amount << " damage points !!" << std::endl;
    this->_hitPoint = this->_hitPoint - amount;
    std::cout << this->_name << " currently has " << this->_hitPoint << " hit points !!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (this->_energyPoint <= 0){
        std::cout << this->_name << " doesn't have enough Enerygy Point" << std::endl;
        return ;
    }
    if (this->_hitPoint <= 0){
        std::cout << this->_name << " has already fainted (0 Hit Point)" << std::endl;
        return ;
    }
    std::cout << this->_name << " has repaired " << amount << " hit points !!" << std::endl;
    this->_hitPoint = this->_hitPoint + amount;
    this->_energyPoint--;
    std::cout << this->_name << " currently has " << this->_hitPoint << " hit points !!" << std::endl;
    std::cout << this->_name << " currently has " << this->_energyPoint << " energy points !!" << std::endl;
}

void ClapTrap::Showinfo(ClapTrap const &c){
    std::cout << c.getName() << " has " << c.getHitPoint() << " hit points and " << c.getEnergyPoint() << " energy points left" << std::endl;
}

std::ostream &operator<<(std::ostream &out, ClapTrap &c){
    out << c.getName();
    return (out);
}