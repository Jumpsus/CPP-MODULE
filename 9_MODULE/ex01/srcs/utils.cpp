#include "utils.hpp"
#include <string>

bool    IsDigit(std::string    input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return false;
    }
    return true;
}

bool    IsOperator(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'))
            return false;
    }
    return true;
}

static int  countWord(std::string   line)
{
    int     count = 0;
    bool    trigger = true;

    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ' && trigger)
        {
            trigger = false;
            count++;
        } else if (line[i] == ' ') {
            trigger = true;
        }
    }
    return (count);
}

static int  wordLength(std::string   line, int index)
{
    int     add = 0;

    while (line[index + add] && line[index + add] != ' ')
    {
        add++;
    }
    return (add);
}

std::string* FtSplit(std::string line)
{
    std::string *result = new std::string[countWord(line) + 1];

    int     count = 0;
    int     index = 0;

    while (line[index])
    {
        if (line[index] == ' ')
        {
            index++;
        } else {
            int len = wordLength(line, index);
            result[count] = line.substr(index, len);
            index += len;
            count++;
        }
    }
    result[count] = "";
    return (result);
}