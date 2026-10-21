#include "Span.hpp"

Span::Span() : _maxN(0)
{
}
Span::Span(unsigned int n) : _maxN(n)
{
}
Span::Span(const Span &original) : _maxN(original._maxN), _v(original._v)
{
}
Span &Span::operator=(const Span &original)
{
    if (this != &original)
    {
        this->_maxN = original._maxN;
        this->_v = original._v;
    }
    return *this;
}
Span::~Span()
{
}
void Span::addNumber(unsigned int num)
{
    if (this->_v.size() == this->_maxN)
        throw Span::SpanFullException();
    this->_v.push_back(num);
}
unsigned int Span::shortestSpan()
{
    if (_v.size() == 0 || _v.size() == 1)
        throw Span::EmptySpanException();
    std::sort(_v.begin(), _v.end());
    unsigned int distance = _v[1] - _v[0];
    for (unsigned int i = 0; i < _v.size() - 1; i++)
    {
        if (_v[i + 1] - _v[i] < distance)
            distance = _v[i + 1] - _v[i];
    }
    return distance;
}

unsigned int Span::longestSpan()
{
    if (_v.size() == 0 || _v.size() == 1)
        throw Span::EmptySpanException();
    std::sort(_v.begin(), _v.end());

    return _v[_v.size() - 1] - _v[0];
}