#ifndef UTILS_HPP
# define UTILS_HPP

#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>

typedef struct ConvertedTime{
    time_t  value;
    bool    success;
} ConvertedTime;

typedef struct ConvertedRate{
    float   value;
    bool    success;
} ConvertedRate;

ConvertedTime   ConvertStringToTime(std::string timeFormat);
ConvertedRate   ConvertRate(std::string rate);

time_t          DecreaseDate(time_t time);
std::string     Trim(std::string input);

#endif
