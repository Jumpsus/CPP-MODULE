#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap{
    public: 
        FragTrap();
        FragTrap(std::string const name);
        FragTrap(FragTrap const &f);
        ~FragTrap();
        FragTrap &operator=(FragTrap const &f);
        void    attack(std::string  const &target);
        void    highFiveGuys();
};

std::ostream &operator<<(std::ostream &out, FragTrap &f);

#endif