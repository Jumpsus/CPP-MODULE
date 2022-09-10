#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat: public Animal{
    public:
        Cat();
        Cat(Cat const &cat);

        ~Cat();

        Cat &operator=(Cat const &cat);
        void makeSound();
};

std::ostream &operator<<(std::ostream &out, Cat &cat);

#endif