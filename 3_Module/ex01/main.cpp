#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ScavTrap attacker("Hooligan Clap");
    ScavTrap victim("Victim Clap");

    for (int i =0; i <= 10; i++){
        std::cout << "********** Loop: " << i + 1 << " **********" << std::endl;
        std::cout << "=== Hoologan Clap attack ==="<< std::endl;
        attacker.attack(victim.getName());
        std::cout << "=== Victim Clap take damage ==="<< std::endl;
        victim.takeDamage(20);
        std::cout << "=== Victim Clap repair itself ==="<< std::endl;
        victim.beRepaired(1);
        std::cout << "=== Hoologan Clap attack ==="<< std::endl;
        attacker.guardGate();
        std::cout << "=== Victim Clap attack back!! ==="<< std::endl;
        victim.attack(attacker.getName());
        std::cout << "But " << attacker.getName() << " is on GUARD !!" << std::endl;
        std::cout << std::endl;
        ClapTrap::Showinfo(attacker);
        ClapTrap::Showinfo(victim);
        std::cout << std::endl;
        std::cout << "==========================================" << std::endl;
    }
}