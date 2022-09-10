#include "Zombie.hpp"

void setZombieHordeName( int n, std::string name, Zombie *zombieHorde ){
    for (int i = 0; i < n; i++){
        zombieHorde[i].setName(name);
        zombieHorde[i].announce();
    }
}

Zombie* zombieHorde( int n, std::string name ){
    Zombie *z = new Zombie[n];
    setZombieHordeName(n, name, z);
    return (z);
}