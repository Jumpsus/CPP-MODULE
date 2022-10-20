#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(){

    {
        std::cout << "=== Normal Case ===" << std::endl;
        Cat cat;
        Dog dog;

        Animal *a1 = &cat;
        Animal *a2 = &dog;

        a1->makeSound();
        a2->makeSound();
        std::cout << std::endl;
    }
    {
        // std::cout << "=== Error Case === (Need to uncomment in main)" << std::endl;
        // Animal animal;

        // animal->makeSound();
    }
    
}