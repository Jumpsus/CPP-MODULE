#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    public: 
        ScavTrap();
        ScavTrap(std::string const name);
        ScavTrap(ScavTrap const &s);
        ~ScavTrap();
        ScavTrap &operator=(ScavTrap const &s);
        void    attack(std::string  const &target);
        void    guardGate();
};

std::ostream &operator<<(std::ostream &out, ScavTrap &s);

#endif