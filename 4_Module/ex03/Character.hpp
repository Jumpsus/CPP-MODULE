#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter{
    public:
        Character();
        Character(const std::string &n);
        ~Character();

        Character(Character const &c);
        Character &operator=(Character const &c);

        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        static bool         _verbose;

    private:
        std::string         _name;

        static const int    _maxSlot = 4;
        AMateria            *_slot[_maxSlot];
};

#endif