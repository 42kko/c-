#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <iostream>
#include <fstream>

class bitcoinExchange
{
    private:
        typedef std::map<std::string, double> Mmap;
        typedef std::pair<std::string, double> Mpair;
        Mmap _mmap;
        bool isValid(std::string c, char ident);
        bool dateValid(std::string date);
        bool valueValid(std::string value);
        bitcoinExchange();
        std::string ft_trim(std::string c);
    public:
        bitcoinExchange(char *s);
        ~bitcoinExchange();
        bitcoinExchange(const bitcoinExchange &c);
        bitcoinExchange& operator=(const bitcoinExchange &c);
        void exchange(const char *s);
        void setup(const char *s);
};

#endif