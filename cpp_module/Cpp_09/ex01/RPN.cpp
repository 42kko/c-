#include "RPN.hpp"

rpn::rpn()
{

}

rpn::rpn(char *s)
{
    while ((*s))
    {
        if (*s >= '0' && *s <= '9')
            _ms.push(*s - '0');
        else if (*s == '*' || *s == '+' || *s == '/' || *s == '-')
        {
            if (_ms.size() < 2)
                throw (std::string("Error1"));
            int i = _ms.top();
            _ms.pop();
            int j = _ms.top();
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
            throw (std::string("Error"));
        (s)++;
    }
    if (_ms.size() == 1)
        std::cout << _ms.top() << std::endl;
}

rpn::~rpn()
{

}

rpn::rpn(const rpn &c)
{

}

rpn& rpn::operator=(const rpn &c)
{

}