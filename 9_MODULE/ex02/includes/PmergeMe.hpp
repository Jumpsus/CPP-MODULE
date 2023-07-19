#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <sys/time.h>
# include "utils.hpp"

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(int *input, size_t size);
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();

        std::vector<int>    GetContainerA();
        std::list<int>      GetContainerB();
        void                SortAndShowResult();
    private:
        std::vector<int>    containerA;
        std::list<int>      containerB;

        void                mergeSortContainerA();
        void                mergeSortContainerB();

        bool                crossCheck();
};

#endif