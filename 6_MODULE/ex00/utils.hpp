#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <limits>

std::string     convertToStr(char *input);
int             isSpecialCase(std::string input);
int             getType(std::string input);

void            printChar(unsigned char input);
void            printInt(int input);
void            printFloat(float input);
void            printDouble(double input);

#endif