#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongDog: public WrongAnimal{
    public:
        WrongDog();
        WrongDog(WrongDog const &dog);
        ~WrongDog();

        WrongDog &operator=(WrongDog const &dog);
        
        void makeSound() const;
};

std::ostream &operator<<(std::ostream &out, WrongDog &dog);

#endif