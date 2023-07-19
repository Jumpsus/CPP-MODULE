#ifndef UTILS_HPP
#define UTILS_HPP

# include <vector>
# include <list>
# include <iostream>
# include <cstdlib>
# include <sys/time.h>

typedef struct Element{
    int*    value;
    size_t  size;
    bool    success;  
} Element;

bool            IsDigit(std::string    input);
Element         FtSplitElement(std::string line);
Element         FillElement(int argc, char **argv);

template<class T>
void    PrintContainer(T container)
{
    typename T::iterator    iter = container.begin();

    while (iter != container.end())
    {
        std::cout << *iter << " ";
        iter++;
    }
    std::cout << std::endl;
}

template<class T>
void    SortVector(std::vector<T> *vec, typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
{
    typename std::vector<T>::iterator  iter = start;

    while (iter != end)
    {
        int i = 0;
        while (((iter - i) != start) && (*iter < *(iter - i - 1)))
        {
            i++;
        }
        if (iter != (iter - i))
        {
            T temp = *iter;
            vec->erase(iter);
            vec->insert(iter - i, temp);
        }
        iter++;
    }
    return ;
}

template<class T>
void    SortList(std::list<T> *list, typename std::list<T>::iterator start, typename std::list<T>::iterator end)
{
    typename std::list<T>::iterator  iter = start;
    typename std::list<T>::iterator  beforeStart = start;
    beforeStart--;

    while (iter != end)
    {
        typename std::list<T>::iterator  travel = iter;
        travel--;
        while ((travel != beforeStart) && (*iter < *travel))
        {
            travel--;
        }
        if (++travel != iter)
        {
            T temp = *iter;
            list->erase(iter);
            list->insert(travel, temp);
        }
        iter++;
    }
    return ;
}

#endif
