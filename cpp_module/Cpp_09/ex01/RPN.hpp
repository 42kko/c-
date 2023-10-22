#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class rpn
{
    private:
        rpn();
        rpn(const rpn &c);
        rpn& operator=(const rpn &c);
        std::stack<ssize_t> _ms;
    public:
        rpn(char *s);
        ~rpn();
};

#endif

