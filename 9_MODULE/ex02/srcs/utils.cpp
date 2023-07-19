#include "utils.hpp"
#include <vector>
#include <list>
#include <iostream>

bool    IsDigit(std::string    input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
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

Element FtSplitElement(std::string line)
{
    Element result;
    result.success = false;

    int *split = new int[countWord(line)];

    int     count = 0;
    int     index = 0;

    while (line[index])
    {
        if (line[index] == ' ')
        {
            index++;
        } else {
            int len = wordLength(line, index);
            std::string word = line.substr(index, len);
            if (!IsDigit(word))
            {
                delete []split;
                return (result);
            }
            split[count] = std::atoi(line.substr(index, len).c_str());
            index += len;
            count++;
        }
    }

    result.value = split;
    result.size = count;
    result.success = true;
    
    return (result);
}

Element FillElement(int argc, char **argv)
{
    Element result;
    result.success = false;

    int     *value = new int[argc - 1];
    int     index = 0;

    for (int i = 1; i < argc; i++)
    {
        if (!IsDigit(argv[i]))
        {
            std::cout << "Error" << std::endl;
            delete []value;
            return(result);
        }
        value[index++] = std::atoi(argv[i]);
    }

    result.value = value;
    result.size = index;
    result.success = true;

    return (result);
}