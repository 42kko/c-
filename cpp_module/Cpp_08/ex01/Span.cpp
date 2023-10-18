#include "Span.hpp"

Span::Span() : _sorted(false)
{
}

Span::Span(const size_t &i) : _sorted(false)
{
    _max = i;
}

Span::~Span()
{
}

Span::Span(const Span &c)
{
    *this = c;
}

Span& Span::operator=(const Span &c)
{
    if (this == &c)
        return *this;
    _vec = c._vec;
    return *this;
}

void Span::addNumber(const double &t)
{
    if (_vec.size() > _max - 1)
        throw std::string ("Err: Span size is full");
    _vec.push_back(t);
    _sorted = false;
}


double Span::shortestSpan()
{
    if (!_sorted)
    {
        std::sort(_vec.begin(), _vec.end());
        _sorted = true;
    }
    if (_vec.size() == 0 || _vec.size() == 1)
        throw std::string("Err: Distance cannot be measured");
    double ret = INT_MAX;
    for (size_t i = 1; i < _vec.size(); ++i)
    {
        if (ret > _vec[i] - _vec[i - 1])
            ret = _vec[i] - _vec[i - 1];
    }
    return ret;
}

double Span::longestSpan()
{
    if (!_sorted)
    {
        std::sort(_vec.begin(), _vec.end());
        _sorted = true;
    }
    if (_vec.size() == 0 || _vec.size() == 1)
        throw std::string("Err: Distance cannot be measured");
    return (*(_vec.end() - 1) - *(_vec.begin()));
}

void Span::fillUp()
{
    srand(time(0));
    for (size_t i = 0; i < _max; i++)
    {
        double d = rand();
        _vec.push_back(d);
    }
}