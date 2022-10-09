#include "Harl.hpp"

int getComplainIndex(char *complain){
    std::string complainList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++){
        if (complainList[i] == complain)
            return (i);
    }
    return (-1);
}

int main(int argc, char *argv[]){

    int     index;
    Harl    harl;

    if (argc != 2){
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }

    index = getComplainIndex(argv[1]);

    while (index < 4){
        switch(index){
            case (0):
                std::cout << "[ DEBUG ]" << std::endl;
                harl.complain("DEBUG");
                std::cout << std::endl;
                break ;
            case (1):
                std::cout << "[ INFO ]" << std::endl;
                harl.complain("INFO");
                std::cout << std::endl;
                break ;
            case (2):
                std::cout << "[ WARNING ]" << std::endl;
                harl.complain("WARNING");
                std::cout << std::endl;
                break ;
            case (3):
                std::cout << "[ ERROR ]" << std::endl;
                harl.complain("ERROR");
                return (0);
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
                return (0);
        }
        index++;
    }
}