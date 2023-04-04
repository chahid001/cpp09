#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::parsePush(std::string data)
{
    std::string date;
    float value;

    date = data.substr(0, data.find(","));
    value = atof(data.substr(data.find(",")+1, data.length()).c_str());

    this->database[date] = value;
}

void BitcoinExchange::readDb()
{
    std::ifstream db("data.csv");
    std::string data;


    while(std::getline(db, data))
    {
        if (data != "date,exchange_rate")
            parsePush(data);
    }
}

bool BitcoinExchange::checkDate(std::string date)
{
    int year,month,day;
    struct tm t_date;
    memset(&t_date, 0, sizeof(struct tm));
    if (date.length() != 10)
        return (false);
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return (false);
        }
        else
        {
            if (date[i] < '0' || date[i] > '9')
                return (false);
        }
    }

    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5,7).c_str());
    day = atoi(date.substr(8).c_str());
    
    t_date.tm_year = year - 1900;
    t_date.tm_mon = month - 1;
    t_date.tm_mday = day;

    time_t cal = mktime(&t_date);
    if (cal == -1)
        return (false);
    std::cout << t_date.tm_year << std::endl;
    std::cout << t_date.tm_mon << std::endl;
    std::cout << t_date.tm_mday << std::endl;
    if (t_date.tm_year != year - 1900 || t_date.tm_mon != month - 1 || t_date.tm_mday != day)
        std::cout << "s" << std::endl;
    return (true);
}

float BitcoinExchange::checkValue(std::string value)
{
    char* ptr;
    float val;

    val = strtof(value.c_str(), &ptr);

    if (value[0] == '.')
        return (-1.0);
    else if (*ptr == '\0')
    {
        if (val < 0.0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            return(0.0);
        }    
        else if (val >= 2147483648.0)
        {
            std::cout << "Error: too large a number." << std::endl;
            return (0.0);
        }
        else
            return (val);
    }
    else
        return (-1.0);
    
}

void BitcoinExchange::findCalc(std::string date, float value)
{
    std::map<std::string, float>::iterator it = this->database.find(date);
    if (it != this->database.end())
        std::cout << date << " => " << value << " = " << value*it->second << std::endl;
    else
    {
        std::map<std::string, float>::iterator lower = this->database.end();
        for (it = this->database.begin(); it != lower; it++)
        {
            if (it->first <= date)
                lower = it;
            else
                break;
        }
        if (it == this->database.begin())
            std::cout << date << " => " << value << " = " << value*it->second << std::endl;
        else if (it == this->database.end())
        {
            it--;
            std::cout << date << " => " << value << " = " << value*it->second << std::endl;
        }
        else
        {
            std::cout << date << " => " << value << " = " << value*lower->second << std::endl;
        }
    }
}

void BitcoinExchange::readParse(char *argv)
{
    std::ifstream file(argv);
    std::string input;
    std::string date;
    float value;

    while (std::getline(file, input))
    {
        if (input != "date | value")
        {
            size_t pos = input.find("|");
            if (pos == std::string::npos || pos == 0 || pos == input.length() - 1)
            {
                std::cout << "Error: bad input => " << input << std::endl;
                continue;
            }
            date = input.substr(0, pos-1);
            if (!checkDate(date))
            {
                std::cout << "Error: bad input => " << input << std::endl;
                continue;  
            }
            value = checkValue(input.substr(pos+2));
            if (value == 0.0)
                continue;
            else if (value == -1.0)
            {
                std::cout << "Error: bad input => " << input << std::endl;
                continue; 
            }
            findCalc(date, value);
        }
    }
}