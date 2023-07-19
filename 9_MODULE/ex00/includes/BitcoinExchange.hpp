#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <map>
# include <ctime>
# include "utils.hpp"

class BitcoinExchange
{
    public:
        BitcoinExchange();

        BitcoinExchange(BitcoinExchange const &other);

        BitcoinExchange &operator=(BitcoinExchange const &other);

        ~BitcoinExchange();

        void InsertRate(std::string time, std::string rate);

        void Exchange(std::string time, std::string amount);

    private:
        time_t                      min;
        time_t                      max;
        int                         count;
        std::map<time_t, float>     exchangeMap;

};

#endif