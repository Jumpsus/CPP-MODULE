#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    ClapTrap clap("Job the ClapTrap");
    FragTrap frag("Jam the FragTrap");
    ScavTrap scav("Jump the ScavTrap");

    for (int i =0; i <= 5; i++){
        std::cout << "**************** Loop: " << i + 1 << " ****************" << std::endl;
        std::cout << "=== Clap attack Scav ==="<< std::endl;

        clap.attack(scav.getName());
        if (clap.getEnergyPoint() > 0 && clap.getHitPoint() > 0)
            scav.takeDamage(clap.getAttackDamage());
        std::cout << std::endl;

        std::cout << "=== Scav attack Frag ==="<< std::endl;

        scav.attack(frag.getName());
        if (scav.getEnergyPoint() > 0 && scav.getHitPoint() > 0)
            frag.takeDamage(scav.getAttackDamage());
        std::cout << std::endl;

        std::cout << "=== Frag attack Clap ==="<< std::endl;

        frag.attack(clap.getName());
        if (frag.getEnergyPoint() > 0 && frag.getHitPoint() > 0)
            clap.takeDamage(frag.getAttackDamage());
        std::cout << std::endl;

        std::cout << "=== Everyone use special effect ==="<< std::endl;

        clap.beRepaired(1);
        scav.guardGate();
        frag.highFiveGuys();
        std::cout << std::endl;

        std::cout << "=== SUMMARY ==="<< std::endl;

        ClapTrap::Showinfo(clap);
        ClapTrap::Showinfo(scav);
        ClapTrap::Showinfo(frag);
        std::cout << std::endl;
        
        std::cout << "******************************************" << std::endl;
    }
}