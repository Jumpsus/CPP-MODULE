#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T>{
    public:
        MutantStack<T>()
                :std::stack<T>(){

        };

        MutantStack<T>(const MutantStack<T> &m)
                :std::stack<T>(m){ 
        };

        MutantStack<T> &operator=(const MutantStack<T> &m){
            if (this == &m){
                return (*this);
            }
            this->c = m.c;
            return (*this);
        };

        ~MutantStack<T>(){

        };

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator    begin(){
            return (this->c.begin());
        };

        iterator    end(){
            return (this->c.end());
        };
};
#endif