#include <iostream>
#include <string>
#include <stdlib.h>
#include "utils.hpp"

//check conversion overflow int
template <typename T>
bool IsIntOverflow(T input){
    if (input > static_cast<T>(std::numeric_limits<int>::max()) || (input < static_cast<T>(std::numeric_limits<int>::min())))
        return true;
    return false;
}

//check conversion overflow float
template <typename T>
bool IsFloatOverflow(T input){
    if (input == std::numeric_limits<T>::infinity() || input == -std::numeric_limits<T>::infinity())
        return false;
    if (input > static_cast<T>(std::numeric_limits<float>::max()) || (input < static_cast<T>(std::numeric_limits<float>::min())))
        return true;
    return false;
}

void    implement(char *in){
    std::string input = convertToStr(in);

    /* 
        === first detect type : type code === 
        0 - what you give me ?
        1 - char
        2 - int
        3 - float
        4 - double
    */

   int typeCode = getType(input);
   if (!typeCode){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
   }

    /* 
        === second convert to actual type code ===
        === third convert actual type code to other type code ===
    */

    char        scalarChar;
    int         scalarInt;
    float       scalarFloat;
    double      scalarDouble;

    switch (typeCode){
        case (1):
            scalarChar = atoi(in);
            printChar(scalarChar);
            printInt(static_cast<int>(scalarChar));
            printFloat(static_cast<float>(scalarChar));
            printDouble(static_cast<double>(scalarChar));
            break;
        case (2):
            scalarInt = atoi(in);
            printChar(static_cast<unsigned char>(scalarInt));
            printInt(scalarInt);
            printFloat(static_cast<float>(scalarInt));
            printDouble(static_cast<double>(scalarInt));
            break;
        case (3):
            scalarFloat = atof(in);
            if (isSpecialCase(input)){
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            } else {
                printChar(static_cast<unsigned char>(scalarFloat));
                if (IsIntOverflow<float>(scalarFloat))
                    std::cout << "int: impossible" << std::endl;
                else
                    printInt(static_cast<int>(scalarFloat));
            }
            printFloat(scalarFloat);
            printDouble(static_cast<double>(scalarFloat));
            break;
        case (4):
            scalarDouble = strtod(in, NULL);          
            if (isSpecialCase(input)){
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            } else {
                printChar(static_cast<unsigned char>(scalarDouble));
                if (IsIntOverflow<double>(scalarDouble))
                    std::cout << "int: impossible" << std::endl;
                else
                    printInt(static_cast<int>(scalarDouble));
            }
            if (IsFloatOverflow<double>(scalarDouble))
                    std::cout << "float: impossible" << std::endl;
            else
                    printFloat(static_cast<float>(scalarDouble));
            printDouble(scalarDouble);
            break;
    }
}

int main(int argc, char** argv){
    if (argc != 2){
        std::cerr << "Usage: ./convert <args>" << std::endl;
        return (1);
    }

    implement(argv[1]);
}
