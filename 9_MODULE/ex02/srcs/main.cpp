#include "utils.hpp"
#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    Element elem;

    switch (argc){
        case 1:
            std::cout << "Usage: ./PmergeMe <Numbers ...>" << std::endl;
            return(1);
        case 2:
            elem = FtSplitElement(argv[1]);
            break;
        default:
            elem = FillElement(argc, argv);
    }

    if (!elem.success)
    {
        std::cout << "Error" << std::endl;
        return(2);
    }

    PmergeMe p(elem.value, elem.size);
    p.SortAndShowResult();

    delete []elem.value;

    return (0);
}