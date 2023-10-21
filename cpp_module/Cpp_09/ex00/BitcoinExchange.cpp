#include "BitcoinExchange.hpp"

bitcoinExchange::bitcoinExchange()
{

}

bitcoinExchange::~bitcoinExchange()
{

}

bitcoinExchange::bitcoinExchange(const bitcoinExchange &c)
{
    *this = c;
}

bitcoinExchange& bitcoinExchange::operator=(const bitcoinExchange &c)
{
    if (this == &c)
        return *this;
    this->_mmap = c._mmap;
    return *this;
}

bitcoinExchange::bitcoinExchange(char *s)
{
    std::string str;
    std::fstream fs("data.csv");
    if (!fs.is_open())
    {
        throw (std::string ("Error: Db cant open"));
    }
    std::fstream input(s);
    if (!input.is_open())
    {
        throw (std::string ("Error: input file cant open"));
    }
    input.close();
    std::getline(fs, str);
    if (str != "date,exchange_rate")
    {
        throw (std::string ("Error: Db first line is invalid, chack data.csv"));
    }
    str.erase(0, str.size());
    while (!fs.eof())
    {
        std::getline(fs, str);
        std::string value = str.substr(str.find(',') + 1);
        char *p;
        std::strtod(ft_trim(value).c_str(), &p);
        if (*p != 0)
        {
            std::cout << "Error: database error => " << str << std::endl;
        }
        else if (isValid(str, ','))
            _mmap.insert(Mpair(str.substr(0, str.find(',')), std::atof(value.c_str())));
        else
            std::cout << "Error: database error => " << str << std::endl;
        str.erase(0, str.size());
    }
    fs.close();
}

bool bitcoinExchange::dateValid(std::string date)
{
    std::string y, m, d;
	size_t find = date.find('-');
	size_t rfind = date.rfind('-');
	if (find == std::string::npos || rfind == std::string::npos)
		return false;
	y = ft_trim(date.substr(0, find));
	m = ft_trim(date.substr(find + 1, rfind - (find + 1)));
	d = ft_trim(date.substr(date.rfind('-') + 1));
    char *p;
	long dYear = std::strtod(y.c_str(),&p);
    if (*p != 0)
        return false;
	long dMon = std::strtod(m.c_str(), &p);
    if (*p != 0)
        return false;
	long dDay = std::strtod(d.c_str(), &p);
    if (*p != 0)
        return false;
	if (((dYear % 4 == 0 && dYear % 100 != 0) || dYear % 400 == 0) && m.compare("02") == 0)
	{
		if (dDay > 0 && dDay < 30)
			return true;
	}
	else if (dMon > 0 && dMon < 13)
	{
		
		if (dMon < 8 && dMon % 2 == 1 && dDay > 0 && dDay < 32)
			return true;
        else if (dMon < 8 && dMon % 2 == 0 && dDay > 0 && dDay < 31)
            return true;
		else if (dMon > 7 && dMon % 2 == 1 && dDay > 0 && dDay < 31)
            return true;
		else if (dMon > 7 && dMon % 2 == 0 && dDay > 0 && dDay < 32)
			return true;
		else if (m.compare("02") == 0 && (dDay > 0 && dDay < 29))
			return true;
	}
	return false;	
}

bool bitcoinExchange::valueValid(std::string value)
{
    char *p = NULL;
	double ret = std::strtod(value.c_str(), &p);
	if (ret >= 0 && ret <= 10000 && *p == 0)
		return true;
	return false;
}

std::string bitcoinExchange::ft_trim(std::string c)
{
    const std::string WHITESPACE = " \n\r\t\f\v";
    std::string ret;
    size_t start = c.find_first_not_of(WHITESPACE);
    start == std::string::npos ? "" : ret = c.substr(start);
    size_t end = ret.find_last_not_of(WHITESPACE);
    end == std::string::npos ? "" : ret = ret.substr(0, end + 1);
    return ret;
}

bool bitcoinExchange::isValid(std::string c, char ident)
{
    if (c.empty() || c.find(ident) == std::string::npos)
        return false;
    std::string date(ft_trim(c.substr(0, c.find(ident))));
    std::string value(ft_trim(c.substr(c.find(ident) + 1)));
    if (!dateValid(date))
    	return false;
    return true;
}

void bitcoinExchange::exchange(const char *s)
{
    std::fstream fs(s);
    std::string str;
    std::string date;
    std::string value;
    std::getline(fs, str);
    if (str != "date | value")
    {
        std::cout << "Error: Invalid first line" << str << std::endl;
    }
    while (!fs.eof())
    {
        std::getline(fs, str);
        if (str.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << str << std::endl;
            continue;
        }
        date = ft_trim(str.substr(0, str.find('|')));
        value = ft_trim(str.substr(str.find('|') + 1));
        str.erase(0, str.size());
        if (!dateValid(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!valueValid(value))
        {
            if (std::atof(value.c_str()) < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else if (std::atof(value.c_str()) > 1000)
                std::cout << "Error: too large a number." << std::endl;
            else 
                std::cout << "Error: input value not valid => " << value << std::endl;
            continue;
        }
        Mmap::iterator iter = _mmap.upper_bound(date);
        iter--;
        std::cout << date << " => " << value << " = " << iter->second * std::atof(value.c_str()) << std::endl;
    }
}