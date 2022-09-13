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

        T &operator[](const int index) const;

        class OutOfRangeException : public std::exception{
            public:
                virtual const char *what() const throw{
                    return ("<Exception> Index is out of range");
                }
        };
        unsigned int size() const;

    private:
        unsigned int    size;
        T*              typePtr;
};

#endif