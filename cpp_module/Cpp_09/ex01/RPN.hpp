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
        std::stack<int> _ms;
    public:
        rpn(char *s);
        ~rpn();
        rpn(const rpn &c);
        rpn& operator=(const rpn &c);
};

#endif