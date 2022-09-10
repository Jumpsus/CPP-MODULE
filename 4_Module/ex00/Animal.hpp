#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
    public:
        Animal();
        Animal(std::string const &type);
        Animal(Animal &animal);

        ~Animal();

        Animal &operator=(const Animal &animal);
        std::string getType() const;

        virtual void makeSound();
    protected:
        std::string type;
};

std::ostream &operator<<(std::ostream &out, Animal &animal);

#endif