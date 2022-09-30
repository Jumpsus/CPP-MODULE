#include <vector>
#include <iostream>
#include "easyfind.hpp"

template <typename C>
void    display(C container){
    // typename is for make complier under stand that C is template
    typename C::iterator    iter; 
    iter = container.begin();
    std::cout << "[ ";

    while (iter != container.end()){
        std::cout << *iter << " ";
        iter++;
    }
    std::cout << "]" << std::endl;
}

int main(){
    try {
        std::vector<int> example;

        for(int i = 0; i < 10 ; i++){
            example.push_back(i);
        }
        display(example);

        for(int j = 0; j < 20 ; j++){
            std::cout << "Find: " << j << std::endl;
            if (easyfind(example, j)){
                std::cout << "Can find " << j << std::endl << std::endl;
            }
        }
    }
    catch(std::exception &ex){
        std::cout << ex.what() << std::endl;
    }
}