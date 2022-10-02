#include "Zombie.hpp"

int main(){
    std::cout << "=== Create 9 Zombie ===" << std::endl;
    Zombie *zombiegroup = zombieHorde(20, "Armel");

    std::cout << std::endl << "=== Delete Zombie ===" << std::endl;
    delete[] zombiegroup;
    return (0);
}