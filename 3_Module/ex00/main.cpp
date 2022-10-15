#include "ClapTrap.hpp"

int main(){
    ClapTrap attacker("Hooligan Clap");
    ClapTrap victim("Victim Clap");

    for (int i =0; i <= 10; i++){
        std::cout << "**************** Loop: " << i + 1 << " ****************" << std::endl;
        std::cout << "=== Hoologan Clap attack ==="<< std::endl;
        attacker.attack(victim.getName());
        std::cout << std::endl;

        std::cout << "=== Victim Clap take damage ==="<< std::endl;
        victim.takeDamage(0);
        std::cout << std::endl;

        std::cout << "=== Victim Clap rapair itself ==="<< std::endl;
        victim.beRepaired(0);
        std::cout << std::endl;

        std::cout << "=== Victim Clap attack back!! ==="<< std::endl;
        victim.attack(attacker.getName()); 
        std::cout << std::endl;
        ClapTrap::Showinfo(attacker);
        ClapTrap::Showinfo(victim);
        std::cout << std::endl;

        std::cout << "******************************************" << std::endl ;
    }
}