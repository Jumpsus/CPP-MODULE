#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat: public WrongAnimal{
    public:
        WrongCat();
        WrongCat(WrongCat const &cat);

        ~WrongCat();

        WrongCat &operator=(WrongCat const &cat);
        void makeSound() const;
};

std::ostream &operator<<(std::ostream &out, WrongCat &cat);

#endif