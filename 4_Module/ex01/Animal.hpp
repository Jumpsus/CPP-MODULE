#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal{
    public:
        Animal();
        Animal(std::string const &type);
        Animal(Animal &animal);

        virtual ~Animal();

        virtual Animal &operator=(Animal const &animal);
        std::string getType() const;

        virtual void    makeSound();
        virtual Brain   *getBrain() const;
    protected:
        std::string type;
};

std::ostream &operator<<(std::ostream &out, Animal &animal);

#endif