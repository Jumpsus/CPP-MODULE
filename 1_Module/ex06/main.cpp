#include "HarlFilter.hpp"

int main(int argc, char *argv[]){
    HarlFilter    harlFilter;

    if (argc != 2) {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return (1);
    }
    harlFilter.complain(argv[1]);
    return (0);
}