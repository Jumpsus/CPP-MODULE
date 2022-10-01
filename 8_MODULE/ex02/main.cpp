#include "MutantStack.hpp"

int main(){
    MutantStack<int> m;

    for (int    i = 0; i < 10; i++){
        m.push(i * i);
    }

    MutantStack<int>::iterator iter;
    iter = m.begin();
    while (iter != m.end()){
        std::cout << (*iter) << " ";
        iter++;
    }

    std::cout << std::endl;

}