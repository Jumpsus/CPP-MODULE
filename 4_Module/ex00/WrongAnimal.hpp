#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal{
    public:
        WrongAnimal();
        WrongAnimal(std::string const &type);
        WrongAnimal(WrongAnimal &animal);

        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &animal);
        std::string getType() const;

        void makeSound() const;
    protected:
        std::string type;
};

std::ostream &operator<<(std::ostream &out, WrongAnimal &animal);

#endif