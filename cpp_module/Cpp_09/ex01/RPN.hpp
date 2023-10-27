#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class rpn
{
    private:
        std::stack<ssize_t> _ms;
    public:
        rpn();
        rpn(const rpn &c);
        rpn& operator=(const rpn &c);
        ~rpn();
        void calculation(char *s);
};

#endif

