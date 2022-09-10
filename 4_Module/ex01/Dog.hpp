#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog: public Animal{
    public:
        Dog();
        Dog(Dog const &dog);
        ~Dog();

        Dog     &operator=(Dog const &dog);
        Animal  &operator=(Animal const &animal);
        
        void    makeSound();
        Brain   *getBrain() const;
    private:
        Brain *brain;
};

std::ostream &operator<<(std::ostream &out, Dog &dog);

#endif