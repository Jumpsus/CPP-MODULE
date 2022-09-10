#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
    public:
        Weapon();
        Weapon(std::string t);
        ~Weapon();
        std::string getType( void );
        void        setType(std::string t);
    private:
        std::string type;
};

#endif