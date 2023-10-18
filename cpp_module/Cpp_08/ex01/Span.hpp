#ifndef SPAN_HPP
#define SPAN_HPP
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>

class Span
{
    private:
        Span();
        std::vector<double> _vec;
        size_t _max;
        bool _sorted;
    public:
        Span(const size_t &i);
        ~Span();
        Span(const Span &c);
        Span& operator=(const Span &c);
        void addNumber(const double &t);
        double shortestSpan();
        double longestSpan();
        void fillUp();
};

#endif