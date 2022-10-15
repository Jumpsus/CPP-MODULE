#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog: public Animal{
    public:
        Dog();
        Dog(Dog const &dog);
        ~Dog();

        Dog &operator=(Dog const &dog);
        
        void makeSound() const;
};

std::ostream &operator<<(std::ostream &out, Dog &dog);

#endif