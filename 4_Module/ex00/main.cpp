#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(){

    Cat cat;
    Dog dog;

    Animal *a1 = &cat;
    Animal *a2 = &dog;

    a1->makeSound();
    a2->makeSound();
}