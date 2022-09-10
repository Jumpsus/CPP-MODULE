#include "HarlFilter.hpp"

void    HarlFilter::debug( void ){
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    HarlFilter::info( void ){
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    HarlFilter::warning( void ){
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    HarlFilter::error( void ){
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    HarlFilter::complain(std::string level){
    int index;

    void (HarlFilter::*ptrToFunc[4])( void ) = {
        &HarlFilter::debug,
        &HarlFilter::info,
        &HarlFilter::warning,
        &HarlFilter::error
    };
    index = (level == "DEBUG") ? 0 :
            (level == "INFO") ? 1 :
            (level == "WARNING") ? 2 :
            (level == "ERROR") ? 3 : 4;
    switch (index)
    {
        case 0:
            (this->*ptrToFunc[0])();
            (this->*ptrToFunc[1])();
            (this->*ptrToFunc[2])();
            (this->*ptrToFunc[3])();
            break;
        case 1:
            (this->*ptrToFunc[1])();
            (this->*ptrToFunc[2])();
            (this->*ptrToFunc[3])();
            break;
        case 2:
            (this->*ptrToFunc[2])();
            (this->*ptrToFunc[3])();
            break;
        case 3:
            (this->*ptrToFunc[3])();
            break;
        default:
            std::cout << "[Probably complaining about insignificant problems]" << std::endl;
            break;
    }
}