#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
    ClapTrap clap("ClapTrap");
    FragTrap frag("FragTrap");
    ScavTrap scav("ScavTrap");
    DiamondTrap diam("DiamondTrap");

    for (int i =0; i <= 5; i++){
        std::cout << "********** Loop: " << i + 1 << " **********" << std::endl;
        std::cout << "=== Clap attack Scav ==="<< std::endl;

        clap.attack(scav.getName());
        if (clap.getEnergyPoint() > 0 && clap.getHitPoint() > 0)
            scav.takeDamage(clap.getAttackDamage());

        std::cout << "=== Scav attack Frag ==="<< std::endl;

        scav.attack(frag.getName());
        if (scav.getEnergyPoint() > 0 && scav.getHitPoint() > 0)
            frag.takeDamage(scav.getAttackDamage());

        std::cout << "=== Frag attack Diam ==="<< std::endl;

        frag.attack(clap.getName());
        if (frag.getEnergyPoint() > 0 && frag.getHitPoint() > 0)
            diam.takeDamage(frag.getAttackDamage());

        std::cout << "=== Diam attack Clap ==="<< std::endl;
        diam.attack(clap.getName());
        if (diam.getEnergyPoint() > 0 && diam.getHitPoint() > 0)
            clap.takeDamage(diam.getAttackDamage());

        std::cout << "=== Everyone use special effect ==="<< std::endl;

        clap.beRepaired(1);
        scav.guardGate();
        frag.highFiveGuys();
        diam.whoAmI();

        std::cout << "=== SUMMARY ==="<< std::endl;

        ClapTrap::Showinfo(clap);
        ClapTrap::Showinfo(scav);
        ClapTrap::Showinfo(frag);
        ClapTrap::Showinfo(diam);
        std::cout << std::endl;
        
        std::cout << "==========================================" << std::endl;
    }
}