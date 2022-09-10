#include "Zombie.hpp"

int main(){
    std::cout << "=== Heap Zombie ===" << std::endl;
    Zombie *jumpZombie = newZombie("HeapZombie");
    jumpZombie->announce();
    delete(jumpZombie);

    std::cout << std::endl << "=== Stack Zombie ===" << std::endl;
    randomChump("StackZombie");
    return (0);
}