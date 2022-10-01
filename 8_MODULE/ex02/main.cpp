#include "MutantStack.hpp"

int main(){
    MutantStack<int> m;
    MutantStack<int> mcpy(m);

    for (int    i = 0; i < 10; i++){
        m.push(i * i);
    }

    MutantStack<int>::iterator iter;
    mcpy = m;

    for (int    i = 10; i < 20; i++){
        mcpy.push(i * i);
    }

    std::cout << "m mutant stack member : ";
    iter = m.begin();
    while (iter != m.end()){
        std::cout << (*iter) << " ";
        iter++;
    }
    std::cout << std::endl;

    std::cout << "mcpy mutant stack member : ";
    iter = mcpy.begin();
    while (iter != mcpy.end()){
        std::cout << (*iter) << " ";
        iter++;
    }
    std::cout << std::endl;
}