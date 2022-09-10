#include "Zombie.hpp"

void Zombie::announce ( void ){
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(){

}

Zombie::Zombie(std::string n){
    name = n;
    std::cout << "Zombie "<< name << " has been created..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie "<< name << " is destroyed..." << std::endl;
}

void    Zombie::setName(std::string name){
    this->name = name;
    //std::cout << "Set Name Zombie to ->" << this->name << std::endl;
}