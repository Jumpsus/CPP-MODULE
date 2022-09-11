#include <iostream>
#include <string>
#include "utils.hpp"

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
            scalarChar = std::stoi(input);
            printChar(scalarChar);
            printInt(static_cast<int>(scalarChar));
            printFloat(static_cast<float>(scalarChar));
            printDouble(static_cast<double>(scalarChar));
            break;
        case (2):
            scalarInt = std::stoi(input);
            printChar(static_cast<unsigned char>(scalarInt));
            printInt(scalarInt);
            printFloat(static_cast<float>(scalarInt));
            printDouble(static_cast<double>(scalarInt));
            break;
        case (3):
            scalarFloat = std::stof(input);
            if (isSpecialCase(input)){
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            } else {
                printChar(static_cast<unsigned char>(scalarFloat));
                printInt(static_cast<int>(scalarFloat));
            }
            printFloat(scalarFloat);
            printDouble(static_cast<double>(scalarFloat));
            break;
        case (4):
            scalarDouble = std::stod(input);
            if (isSpecialCase(input)){
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            } else {
                printChar(static_cast<unsigned char>(scalarDouble));
                printInt(static_cast<int>(scalarDouble));
            }
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
