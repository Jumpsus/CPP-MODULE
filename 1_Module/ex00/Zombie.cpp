#include "Zombie.hpp"

void Zombie::announce ( void ){
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string n){
    name = n;
    std::cout << "Zombie "<< name << " has been created..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie "<< name << " is destroyed..." << std::endl;
}