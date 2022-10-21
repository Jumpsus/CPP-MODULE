#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria{
    protected:
        std::string const   _type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const &a);

        AMateria &operator=(AMateria const &a);
        virtual ~AMateria();

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        static bool         _verbose;
};

#endif