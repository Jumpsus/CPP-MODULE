#include "Span.hpp"
#include <iterator>
#include <algorithm>
#include <limits.h>

Span::Span(){
    this->_maxsize = 0;
    this->_currentsize = 0;
}

Span::Span(unsigned int size): _maxsize(size), _currentsize(0){

}

Span::~Span(){
    
}

Span::Span(const Span &s):_maxsize(s.maxSize()), _currentsize(s.size()){
    this->_value = s._value;

    /*
    FOR C++11

    for (int value: s._value){
        this->_value.push_back(value);
    }
    */
}

Span    &Span::operator=(const Span &s){

    if (this == &s){
        return (*this);
    }

    this->_value.clear();
    this->_maxsize = s.maxSize();
    this->_currentsize = s.size();

    this->_value = s._value;
    /*
    FOR C++11

    for (int value: s._value){
        this->_value.push_back(value);
    }
    */
    return (*this);
}

unsigned    int     Span::longestSpan(){
    if (this->size() <= 1){
        throw (Span::tooLittleValue());
    }
    std::sort(this->_value.begin(), this->_value.end());
    return (*(this->_value.end() - 1) - *(this->_value.begin()));
}

unsigned    int     Span::shortestSpan(){
    unsigned    int             shortest = INT_MAX;
    unsigned    int             temp;
    std::vector<int>::iterator  iter;

    if (this->size() <= 1){
        throw (Span::tooLittleValue());
    }
    sort(this->_value.begin(), this->_value.end());
    iter = this->_value.begin();
    temp = *(iter);

    iter++;
    while (iter != this->_value.end()){
        if ((*(iter) - temp) < shortest){
            shortest = (*(iter) - temp);
        }
        temp = *(iter);
        iter++;
    }
    return (shortest);
}

void    Span::addNumber(int value){
    if (this->_currentsize >= this->_maxsize){
        throw(Span::exceedMaximumLimit());
    }
    this->_currentsize = (this->_currentsize) + 1;
    this->_value.push_back(value);
}

unsigned    int     Span::size() const{
    return (this->_currentsize);
}

unsigned    int     Span::maxSize() const{
    return (this->_maxsize);
}
