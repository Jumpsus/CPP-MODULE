#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ScavTrap attacker("Hooligan Clap");
    ClapTrap victim("Victim Clap");

    for (int i =0; i <= 50; i++){
        std::cout << "**************** Loop: " << i + 1 << " ****************" << std::endl;
        std::cout << "=== Hooligan Clap attack ==="<< std::endl;
        attacker.attack(victim.getName());
        std::cout << std::endl;
        
        std::cout << "=== Victim Clap take damage ==="<< std::endl;
        victim.takeDamage(20);
        std::cout << std::endl;
        
        std::cout << "=== Victim Clap repair itself ==="<< std::endl;
        victim.beRepaired(20);
        std::cout << std::endl;
        
        std::cout << "=== Hoologan Clap attack ==="<< std::endl;
        attacker.guardGate();
        std::cout << std::endl;
        
        std::cout << "=== Victim Clap attack back!! ==="<< std::endl;
        victim.attack(attacker.getName());
        std::cout << "But " << attacker.getName() << " is on GUARD !!" << std::endl;
        std::cout << std::endl;
        
        ClapTrap::Showinfo(attacker);
        ClapTrap::Showinfo(victim);
        std::cout << std::endl;
        
        std::cout << "******************************************" << std::endl;
    }
}