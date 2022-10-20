#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(){

    Animal  *animals[10];
    Brain   *brain_ptr;

    std::cout << "=== Create 10 Animals: 5 cats and 5 dogs ===" << std::endl;
    for (int i = 0; i < 10 ; i++){
        if ((i % 2) == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    std::cout << std::endl;

    std::cout << "=== 10 Animals: each make sound() ===" << std::endl;
    for (int i = 0; i < 10 ; i++){
        animals[i]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "=== Create Brain for animals[0] ===" << std::endl;
    brain_ptr = animals[0]->getBrain();
    brain_ptr->idea[0] = "Feed me slave";
    brain_ptr->idea[1] = "I gonna scratch you so bad !!";
    brain_ptr->idea[2] = "So you have choosen ... death";
    std::cout << std::endl;

    std::cout << "=== Copy Assignment Animals[0] -> Animals[2] ===" << std::endl;
    *animals[2] = *animals[0];
    std::cout << "Animal [0] Idea [0] : " << animals[0]->getBrain()->idea[0] << std::endl;
    std::cout << "Animal [2] Idea [0] : " << animals[2]->getBrain()->idea[0] << std::endl;
    std::cout << std::endl;

    std::cout << "=== Change Idea of Animals[2] (*expet : Animal[0] shouldn't change) ===" << std::endl;
    animals[2]->getBrain()->idea[0] = "Please Feed me !!";
    std::cout << "Animal [0] Idea [0] : " << animals[0]->getBrain()->idea[0] << std::endl;
    std::cout << "Animal [2] Idea [0] : " << animals[2]->getBrain()->idea[0] << std::endl;
    std::cout << std::endl;

    std::cout << "=== Delete Animals ===" << std::endl;
    for (int j = 0; j < 10 ; j++){
        delete animals[j];
    }
}