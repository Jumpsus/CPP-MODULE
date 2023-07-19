#include "utils.hpp"

static int     countWord(std::string s, char delimeter)
{
    int     count = 0;

    int     find = s.find(delimeter);
    while(find != -1)
    {
        s.erase(s.begin(), s.begin() + find + 1);
        find = s.find(delimeter);
        count++;
    }
    count++;

    return (count);
}

static bool     containOnlyNumber(std::string s)
{
    int i = 0;
    bool trigger = false;

    while (s[i] != 0)
    {
        if ((s[i] < '0' || s[i] > '9') && (s[i] != '.') && (i != 0 && s[i] != '-' && s.length() != 1))
            return false;
        if (s[i] == '.')
        {
            if (trigger)
            {
                return false;
            }
            trigger = true;
        }
        i++;
    }
    return true;
}

ConvertedTime   ConvertStringToTime(std::string timeFormat)
{
    ConvertedTime   result;
    result.success = false;
    
    struct tm   *t;

    time_t  rawtime;
    time ( &rawtime );
    t = localtime ( &rawtime );

    t->tm_sec = 0;
    t->tm_min = 0;
    t->tm_hour = 0;

    int         count;
    
    count = countWord(timeFormat, '-');

    /* validate number of date time */
    if (count != 3)
    {
        return result;
    }

    /* validate date */
    int     find = timeFormat.find('-');
    int     index = 0;

    while(find != -1)
    {
        int time = std::atoi(timeFormat.substr(0, find).c_str());

        switch (index){
            case 0:
                if (time < 0)
                    return result;
                t->tm_year = time - 1900;
                break;
            case 1:
                if (time < 1 || time > 12)
                    return result;
                t->tm_mon = time - 1;
                break;
            default:
                return result;
        }
        if (time < 0)
        {
            return result;
        }

        timeFormat.erase(timeFormat.begin(), timeFormat.begin() + find + 1);
        find = timeFormat.find('-');

        index++;
    }

    int time = std::atoi(timeFormat.substr(0, timeFormat.length() + 1).c_str());
    if (time < 1 || time > 31)
        return result;
    t->tm_mday = time;

    result.value = mktime(t);
    result.success = true;

    return result;
}

ConvertedRate ConvertRate(std::string rate)
{
    ConvertedRate   result;
    result.success = false;

    if (!containOnlyNumber(rate))
    {
        return result;
    }

    result.value = std::atof(rate.c_str());
    result.success = true;

    return result;
}

time_t  DecreaseDate(time_t time)
{
    struct tm   *t;

    t = localtime ( &time );
    t->tm_mday--;

    time_t result = mktime(t);

    return (result);
}

std::string     Trim(std::string input)
{
    int beginIndex = 0;
    int endIndex = input.length() - 1;

    if (beginIndex >= endIndex)
    {
        return ("");
    }

    while (input[endIndex] == ' ')
    {
        endIndex--;
    }

    while (input[beginIndex] == ' ')
    {
        beginIndex++;
    }

    if (beginIndex > endIndex)
    {
        return ("");
    }

    return (input.substr(beginIndex, endIndex + 1));
}
