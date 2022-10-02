#include "Zombie.hpp"
#include<sstream>

void setZombieHordeName( int n, std::string name, Zombie *zombieHorde ){
    for (int i = 0; i < n; i++){
        std::stringstream   ss;
        std::string        number;

        ss << i;
        ss >> number;
        zombieHorde[i].setName(name + " " + number);
        zombieHorde[i].announce();
    }
}

Zombie* zombieHorde( int n, std::string name ){
    Zombie *z = new Zombie[n];
    setZombieHordeName(n, name, z);
    return (z);
}