#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Create Brain..." << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain is destroyed ugh...!!" << std::endl;
}

Brain::Brain(Brain const &brain){
    std::cout << "Create Deep Copy Brain..." << std::endl;
    for (int i = 0; i < 100; i++){
        this->idea[i] = brain.idea[i];
    }
}

Brain &Brain::operator=(Brain const &brain){
    std::cout << "Assign Deep Copy Brain..." << std::endl;
    for (int i = 0; i < 100; i++){
        this->idea[i] = brain.idea[i];
    }
    return (*this);
}