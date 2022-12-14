#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
    public:
        DiamondTrap();
        DiamondTrap(std::string const name);
        DiamondTrap(DiamondTrap const &d);
        ~DiamondTrap();
        DiamondTrap &operator=(DiamondTrap const &d);

        void        attack(std::string const &name);
        void        whoAmI();

        void        setName(std::string name);
        std::string getName() const;
    private:
        std::string _name;
};

std::ostream &operator<<(std::ostream &out, DiamondTrap &d);

#endif