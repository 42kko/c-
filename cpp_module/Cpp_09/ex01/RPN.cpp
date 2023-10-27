#include "RPN.hpp"

rpn::rpn()
{

}

void rpn::calculation(char *s)
{
    while ((*s))
    {
        if (*s >= '0' && *s <= '9')
            _ms.push(*s - '0');
        else if (*s == '*' || *s == '+' || *s == '/' || *s == '-')
        {
            if (_ms.size() < 2)
                throw (std::string("Error: invalid value"));
            ssize_t i = _ms.top();
            _ms.pop();
            ssize_t j = _ms.top();
            _ms.pop();
            switch (*s)
            {
            case 42:
                _ms.push(j * i);
                break;
            case 43:
                _ms.push(j + i);
                break;
            case 47:
                if (i == 0)
                    throw (std::string("Error: Divide by 0"));
                _ms.push(j / i);
                break;
            case 45:
                _ms.push(j - i);
                break;
            default:
                break;
            }
        }
        else if (*s == ' ')
        {
        }
        else
            throw (std::string("Error: invalid value"));
        (s)++;
    }
    if (_ms.size() == 1)
        std::cout << _ms.top() << std::endl;
    else
        std::cout << "Error: check input" << std::endl;
}

rpn::~rpn()
{
}

rpn::rpn(const rpn &c)
{
    *this = c;
}

rpn& rpn::operator=(const rpn &c)
{
    if (this == &c)
        return *this;
    _ms = c._ms;
    return *this;
}