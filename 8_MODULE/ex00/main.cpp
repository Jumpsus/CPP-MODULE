#include <vector>
#include <iostream>
#include <exception>
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

        std::cout << std::endl << "=== Start finding integer from 1 - 20 ===" << std::endl;
        for(int j = 0; j < 20 ; j++){
            std::cout << "Find: " << j << std::endl;
            std::vector<int>::iterator result = easyfind(example, j);
            std::cout << "Result Easy find can found at index " << result - example.begin() << std::endl;
        }
    }
    catch(std::exception &ex){
        std::cout << ex.what() << std::endl;
    }
}