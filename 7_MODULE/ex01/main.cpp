#include "iter.hpp"
#include <iostream>

void    addSuffix(std::string &input){
    input = input + "_suffix";
    return ;
}

template <typename T>
void    print(T &input){
    std::cout << input << std::endl;
    return ;
}

int main(){

    std::string test[5] = {"a", "b", "c", "d", "e"};

    std::cout << "=== Base Data ===" << std::endl;
    iter(test, 5, print);
    std::cout << std::endl << "=== Adding Suffix ===" << std::endl;
    iter(test, 5, addSuffix);
    iter(test, 5, print);

    std::cout << std::endl << "=== Try Integer ===" << std::endl;
    int test2[5] = {1, 2, 3, 4, 5};
    iter(test2, 5, print);

    return(0) ;
}