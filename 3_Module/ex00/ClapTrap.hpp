#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
    public:
        ClapTrap();
        ClapTrap( std::string const name );
        ClapTrap( ClapTrap const &c );

        ~ClapTrap();
        ClapTrap &operator=(ClapTrap const &c);

        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        std::string getName() const;
        int         getHitPoint() const;
        int         getEnergyPoint() const;
        int         getAttackDamage() const;
        static void Showinfo(ClapTrap const &c);

    private:
        std::string _name;
        int         _hitPoint;
        int         _energyPoint;
        int         _attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap &c);

#endif