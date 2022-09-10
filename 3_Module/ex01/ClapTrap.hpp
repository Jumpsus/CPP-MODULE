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
        
        void        setName(const std::string &name);
        void        setHitPoint(int hitPoint);
        void        setEnergyPoint(int energyPoint);
        void        setAttackDamage(int attackDamage);
        static void Showinfo(ClapTrap const &c);

    private:
        std::string name;
        int         hitPoint;
        int         energyPoint;
        int         attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap &c);

#endif