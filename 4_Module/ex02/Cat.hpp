#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat: public Animal{
    public:
        Cat();
        Cat(Cat const &cat);

        ~Cat();

        Cat     &operator=(Cat const &cat);
        Animal  &operator=(Animal const &animal);
        
        void    makeSound();
        Brain   *getBrain() const;
    private:
        Brain *brain;
};

std::ostream &operator<<(std::ostream &out, Cat &cat);

#endif