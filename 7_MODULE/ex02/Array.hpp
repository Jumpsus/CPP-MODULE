#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T> class Array{
    public:
        Array();
        Array(unsigned int n);

        Array(Array const &a); // need to be deep copy
        Array &operator=(Array const &a); // need to be deep copy
        ~Array();

        T &operator[](const unsigned int index) const;

        void    display()const;
        class OutOfRangeException : public std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("<Exception> Index is out of range");
                }
        };
        unsigned int size(void) const;

    private:
        unsigned int    _size;
        T*              _typePtr;
};

template<typename T>
Array<T>::Array():_size(0), _typePtr(nullptr){
    std::cout << "Create empty array" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n):_size(n), _typePtr(nullptr){
    if (n == 0){
        throw(Array::OutOfRangeException());
    }
    std::cout << "Create arrau size " << n << std::endl; 
    _typePtr = new T[n];
    this->display();
}

template<typename T>
Array<T>::Array(Array<T> const &a):_size(a.size()), _typePtr(nullptr){
    if (a.size() == 0){
        return ;
    }
    this->_typePtr = new T[this->_size];
    for (int i = 0; i < a.size(); i++){
        this->_typePtr[i] = a[i];
    }
}

template<typename T>
Array<T>    &Array<T>::operator=(Array<T> const &a){
    if (this->_typePtr != nullptr){
        delete []this->_typePtr;
    }

    this->_size = a.size();
    if (a.size() == 0){
        this->_typePtr = nullptr;
        return (*this);
    }

    this->_typePtr = new T[this->_size];
    for (int i = 0; i < _size; i++){
        this->_typePtr[i] = a[i];
    }
    return (*this);
}

template<typename T>
void    Array<T>::display() const{
    std::cout << "[ ";
    for (unsigned int   i = 0; i < this->size(); i++){
        std::cout << this->_typePtr[i] << " ";
    }
    std::cout << "]" <<std::endl;
}

template<typename T>
T       &Array<T>::operator[](const unsigned int index) const{
    if (index >= this->_size){
        throw(Array::OutOfRangeException());
    }
    return (this->_typePtr[index]);
}

template<typename T>
Array<T>::~Array(){
    std::cout << "Destruct Array" << std::endl;
    if (this->_typePtr == nullptr){
        return ;
    }
    delete []this->_typePtr;
}

template<typename T>
unsigned int    Array<T>::size(void) const{
    return (this->_size);
}

#endif