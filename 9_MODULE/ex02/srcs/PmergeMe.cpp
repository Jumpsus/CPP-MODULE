#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int *input, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        containerA.push_back(input[i]);
        containerB.push_back(input[i]);
    }
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
    this->containerA = other.containerA;
    this->containerB = other.containerB;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &other)
{
    if (this == &other)
    {
        return (*this);
    }

    this->containerA = other.containerA;
    this->containerB = other.containerB;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    
}

std::vector<int>   PmergeMe::GetContainerA()
{
   return(containerA);
}

std::list<int>       PmergeMe::GetContainerB()
{
   return(containerB);
}

bool    PmergeMe::crossCheck()
{
    std::vector<int>::iterator  iterA = containerA.begin();
    std::list<int>::iterator    iterB = containerB.begin();

    int temp = *iterA;

    while (iterA != containerA.end())
    {
        if (*iterA != *iterB || iterB == containerB.end())
        {
            return (false);
        }
        if (temp > *iterA)
        {
            return (false);
        }
        temp = *iterA;

        iterA++;
        iterB++;
    }

    return (iterB == containerB.end());
}

void  PmergeMe::mergeSortContainerA()
{
    size_t group = 2;

    while (group < containerA.size())
    {
        std::vector<int>::iterator travel = containerA.begin();
        std::vector<int>::iterator start = containerA.begin();
        int count = 0;

        while (travel != containerA.end())
        {
            if (count != 0 && (count % group == 0))
            {
                SortVector(&containerA, start, travel);
                start = travel;
            }
            count++;
            travel++;
        }
        if (count != 0)
        {
            SortVector(&containerA, start, travel);
        }
        group *= 2;
    }
    SortVector(&containerA, containerA.begin(), containerA.end());
}

void  PmergeMe::mergeSortContainerB()
{
    size_t group = 2;

    while (group < containerB.size())
    {
        std::list<int>::iterator travel = containerB.begin();
        std::list<int>::iterator start = containerB.begin();
        int count = 0;

        while (travel != containerB.end())
        {
            if (count != 0 && (count % group == 0))
            {
                SortList(&containerB, start, travel);
                start = travel;
            }
            count++;
            travel++;
        }
        if (count != 0)
        {
            SortList(&containerB, start, travel);
        }
        group *= 2;
    }

    SortList(&containerB, containerB.begin(), containerB.end());
}

void  PmergeMe::SortAndShowResult()
{
    std::cout << "Before: ";
    PrintContainer(containerA);

    clock_t startVec = clock();
    this->mergeSortContainerA();
    clock_t endVec = clock();

    clock_t startList = clock();
    this->mergeSortContainerB();
    clock_t endList = clock();

    bool success = this->crossCheck();
    if (!success)
    {
        std::cout << "Error: Sort Failed!" << std::endl;
        return ;
    }
    std::cout << "After: ";
    PrintContainer(containerA);

    std::cout << "Time to process a range of " << containerA.size() << " elements with std::vector : " << endVec - startVec << " us" << std::endl;
    std::cout << "Time to process a range of " << containerB.size() << " elements with std::list : " << endList - startList << " us" << std::endl;
}