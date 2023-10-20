// #include "BitcoinExchange.hpp"
#include <map>
#include <string>
#include <iostream>
#include <fstream>

bool dataValid(std::string c, char ident)
{
    if (c.empty() || c.find(ident) == std::string::npos)
        return false;
    std::string date(c.substr(0, c.find(ident)));
    std::string value(c.find(ident) + 1, '\n');
    
    return true;
}

int main(int ac, char **av)
{
    typedef std::multimap<std::string, double> Mmap;
    typedef std::pair<std::string, double> Mpair;
    std::fstream fs("data.csv");
    std::string str;
    Mmap map;
    Mmap input;
    std::getline(fs, str);
    if (str != "date,exchange_rate")
    {
        std::cout << "err" << std::endl;
        return 0;
    }
    str.erase(0, str.size());
    while (!fs.eof())
    {
        std::getline(fs, str);
        std::string value = str.substr(str.find(',') + 1, '\n');
        if (str.find(",") != std::string::npos)
            map.insert(Mpair(str.substr(0, str.find(',')), std::atof(value.c_str())));
        str.erase(0, str.size());
    }
    fs.close();
    fs.open(av[1]);
    if (ac != 2)
    {
        std::cout << "err" << std::endl;
        return 0;
    }
    if (!fs.is_open())
    {
        std::cout << "err1" << std::endl;
        return 0;
    }
    while (!fs.eof())
    {
        std::getline(fs, str);
        std::string value = str.substr(str.find('|') + 1, '\n');
        if (str.find("|") != std::string::npos)
            input.insert(Mpair(str.substr(0, str.find('|')), std::atof(value.c_str())));
        str.erase(0, str.size());
    }
    // for (Mmap::iterator iter = map.begin(); iter != map.end(); iter++)
    // {
    //     std::cout << iter->first << " : " << iter->second << std::endl;
    // }
    for (Mmap::iterator iter = input.begin(); iter != input.end(); iter++)
    {
        std::cout << iter->first << " : " << iter->second << std::endl;
    }
}