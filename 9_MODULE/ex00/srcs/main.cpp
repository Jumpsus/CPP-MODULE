#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <iostream>
#include <fstream>

static void    setRate(BitcoinExchange *b)
{
    std::string line;

    std::fstream    file("data.csv", std::ios::in);
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            int find = line.find(',');
            std::string  time = line.substr(0, find);
            std::string  rate = line.substr(find + 1, line.length());

            b -> InsertRate(time, rate);
        }
    }
    file.close();
}

static void     exchangeRate(BitcoinExchange *b, std::string filename)
{
    std::string line;

    std::fstream    file(filename.c_str(), std::ios::in);

    if (file.is_open())
    {
        /* skip header file */
        std::getline(file, line);
        while (std::getline(file, line))
        {
            int find = line.find('|');
            if (find < 0)
            {
                std::cerr << "Error: bad input => " << line << std::endl;   
            } else {
                std::string  time = Trim(line.substr(0, find));
                std::string  rate = Trim(line.substr(find + 1, line.length()));

                b -> Exchange(time, rate);
            }
        }
    }
    file.close();
}

int main (int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Usage: ./btc <filename>" << std::endl;
        return (1);
    }
    BitcoinExchange b;

    setRate(&b);

    exchangeRate(&b, argv[1]);
}
