#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():count(0)
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other):min(other.min), max(other.max), count(other.count), exchangeMap(other.exchangeMap)
{

}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        return (*this);
    }
    this->min = other.min;
    this->max = other.max;
    this->count = other.count;
    this->exchangeMap = other.exchangeMap;
    
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    exchangeMap.clear();
}

void BitcoinExchange::InsertRate(std::string timeString, std::string rateString){
    
    ConvertedTime   convTime = ConvertStringToTime(timeString);
    ConvertedRate   convRate = ConvertRate(rateString);

    if (!convTime.success || !convRate.success)
    {
        // std::cerr << "Error: Fail Set Rate : " << timeString << ", " << rateString << std::endl;
        return ;
    }

    time_t  time = convTime.value;
    float   rate = convRate.value;

    if (count == 0)
    {
        min = time;
        max = time;
    }

    if (time < min)
    {
        min = time;
    }

    if (time > max)
    {
        max = time;
    }

    exchangeMap.insert(std::pair<time_t, float>(time, rate));
    count++;
}

void BitcoinExchange::Exchange(std::string timeString, std::string amountString){
    
    ConvertedTime   convTime = ConvertStringToTime(timeString);
    ConvertedRate   convRate = ConvertRate(amountString);

    if (!convTime.success)
    {
        std::cerr << "Error: bad input => " << timeString << std::endl;
        return;
    }

    time_t time = convTime.value;

    if (!convRate.success)
    {
        std::cerr << "Error: bad input => " << amountString << std::endl;
        return;
    }

    if (convRate.value < 0.0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }

    if (convRate.value > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }

    float amount = convRate.value;

    time_t  key = time;

    if (time < min)
    {
        std::cerr << "Error: too old exchange date." << std::endl;
        return ;
    }

    if (time > max)
    {
        key = max;
    }

    while (exchangeMap.find(key) == exchangeMap.end())
    {
        key = DecreaseDate(key);
    }

    std::map<time_t, float>::iterator res = exchangeMap.find(key);

    std::cout << timeString << " => " << amountString 
              << " = " << (amount * res->second) << std::endl; 
}

