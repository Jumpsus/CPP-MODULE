#include "utils.hpp"

/* 
    === type code === 
    0 - what you give me ?
    1 - char
    2 - int
    3 - float
    4 - double
*/

std::string    convertToStr(char *input){
    int             i;
    std::string     result;

    i = 0;
    while (input[i]){
        result.push_back(input[i]);
        i++;
    }
    return (result);
}

int        isSpecialCase(std::string input){
    if (!input.compare("+inff") || !input.compare("-inff") || !input.compare("nanf")){
        return (3);
    }
    if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan")){
        return (4);
    }
    return (0);
}

bool        isOnlyChar(std::string input){
    // check only one character and not 0 - 9
    if (input.length() == 1 && (input[0] < '0' || input[0] > 9)){
        return true;
    }
    return false;
}

int         getType(std::string input){
    int     i = 0;
    int     dotFlag = 0;
    int     powFlag = 0;
    int     fFlag = 0;

    if (isSpecialCase(input)){
        return (isSpecialCase(input)); // 3 or 4
    }

    if (isOnlyChar(input)){
        return (1); // case: Only Char ex. '*'
    }

    if (input[i] == '-'){
        i++;
    }
    if (input[i] == '.' && input[i + 1] == 'f'){
        return (0);
    }

    while ((input[i] >= '0' && input[i] <= '9') ||\
            (input[i] == '.' && !dotFlag) ||\
            (input[i] == 'e' && !powFlag) ||\
            (input[i] == 'f' && !fFlag)){
        switch (input[i]){
            case '.': // dot cannot placed after 'e' or 'f'
                dotFlag++;
                if (powFlag)
                    return (0);
                break;
            case 'e':
                powFlag++;
                break;
            case 'f': // need to place after '.' and being last character
                fFlag++;
                if (!dotFlag)
                    return (0);
                break;
        }
        i++;
        if (fFlag)
            break;
    }
    if (!input[i]){
        if (dotFlag){
            if (fFlag){
                return (3); // case: float
            }
            return (4); // case: double
        }
        return (2); // case: int
    }

    return (0); // case: what you give me ?
}

void        printChar(unsigned char input){
    if (input < 32 || input > 127){
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: '" << input << "'" << std::endl;
}

void        printInt(int input){
    std::cout << "int: " << input << std::endl;
}

void            printFloat(float input){
    if ((input - static_cast<int>(input)) == static_cast<float>(0)){
        std::cout.precision(1);
        std::cout << std::fixed;
    }
    std::cout << "float: " << input << "f" << std::endl;
}

void            printDouble(double input){
    if ((input - static_cast<int>(input)) == static_cast<double>(0)){
        std::cout.precision(1);
        std::cout << std::fixed;
    }
    std::cout << "double: " << input << std::endl;
}
