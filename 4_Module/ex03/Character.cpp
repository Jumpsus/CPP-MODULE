#include "Character.hpp"
#include "AMateria.hpp"

bool    Character::_verbose = false;

Character::Character(){
    if (Character::_verbose)
        std::cout << "Create Default Constructor Character !" << std::endl;
    for (int i = 0; i < Character::_maxSlot; i++){
            this->_slot[i] = NULL;
    }
}

Character::Character(const std::string &n) : _name(n){
    if (Character::_verbose)
        std::cout << "Create Constructor Character name: " << this->_name << std::endl;
    for (int i = 0; i < Character::_maxSlot; i++){
            this->_slot[i] = NULL;
    }
}

Character::~Character(){
    if (Character::_verbose)
        std::cout << "Call Destructor Character !" << std::endl;
    for (int i = 0; i < Character::_maxSlot; i++){
        if (this->_slot[i]){
            delete this->_slot[i];
            this->_slot[i] = NULL;
        }
    }
}

Character::Character(Character const &c){
    if (Character::_verbose)
        std::cout << "Copy Constructor Character name: " << this->_name << std::endl;
    (*this) = c;
}

Character &Character::operator=(Character const &c){
    for (int i = 0; i < Character::_maxSlot; i++){
        if (this->_slot[i]){
            delete this->_slot[i];
        }
        if (c._slot[i]){
            this->_slot[i] = c._slot[i]->clone();
        } else {
            this->_slot[i] = NULL;
        }
    }
    this->_name = c.getName();
    if (Character::_verbose)
        std::cout << "Assign Copy operator Character name: " << this->_name << std::endl;
    return (*this);
}

std::string const &Character::getName() const{
    return (this->_name);
}

void    Character::equip(AMateria* m){
    for (int i = 0; i < Character::_maxSlot; i++){
        if (!this->_slot[i]){
            std::cout << this->_name << " equip " << m->getType() <<std::endl;
            this->_slot[i] = m;
            return ;
        }
    }
    std::cout << this->_name << "'s slot is full !!" <<std::endl;
}

void    Character::unequip(int idx){
    if (idx >= Character::_maxSlot){
        std::cout << "index is out of range" << std::endl;
        return ;
    }
    if (!this->_slot[idx]){
        std::cout << this->_name << "'s slot " << idx << " has already empty" << std::endl;
        return ;
    }
    std::cout << this->_name << " unequip " << this->_slot[idx]->getType() <<std::endl;
    delete this->_slot[idx];
    this->_slot[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target){
    if (idx >= Character::_maxSlot){
        std::cout << "index is out of range" << std::endl;
        return ;
    }
    if (!this->_slot[idx]){
        std::cout << this->_name << "'s slot " << idx << " is emptied" << std::endl;
        return ;
    }
    this->_slot[idx]->use(target);
}