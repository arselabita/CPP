#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}
Fixed::Fixed(const int intValue) : _value(intValue << _fractBits)
{
}
Fixed::Fixed(const float floatValue) : _value(roundf(floatValue * (1 << _fractBits)))
{
}
Fixed::Fixed(const Fixed &original) : _value(original.getRawBits())
{
}
Fixed &Fixed::operator=(const Fixed &original)
{
    if (this != &original)
        this->_value = original.getRawBits();
    return *this;
}
Fixed::~Fixed()
{
}
int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _fractBits);
}
int Fixed::toInt(void) const
{
    return _value >> _fractBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}

// comparison
bool Fixed::operator<(const Fixed &other) const
{
    return _value < other._value;
}
bool Fixed::operator>(const Fixed &other) const
{
    return _value > other._value;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return _value >= other._value;
}
bool Fixed::operator<=(const Fixed &other) const
{
    return _value <= other._value;
}
bool Fixed::operator==(const Fixed &other) const
{
    return _value == other._value;
}
bool Fixed::operator!=(const Fixed &other) const
{
    return _value != other._value;
}

// arithmetic add, decrement, multiply, divide
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed num;
    long long fixPointNumber = (long long)_value * other._value;
    num.setRawBits((int)(fixPointNumber >> _fractBits));
    return num;
}
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed num;
    num._value = _value + other._value;
    return num;
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed num;
    num._value = _value - other._value;
    return num;
}
Fixed Fixed::operator/(const Fixed &other) const
{
    if (other._value == 0)
        throw std::runtime_error("Division by zero!!");
    Fixed num;
    long long numerator = (long long)_value << _fractBits;
    long long division = numerator / other._value;
    num.setRawBits((int)(division));
    return num;
}

// Increment, decrement, post increment, post decrement
Fixed &Fixed::operator++()
{
    ++this->_value;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_value++;
    return temp;
}
Fixed &Fixed::operator--()
{
    --this->_value;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_value--;
    return temp;
}

// overloaded member functions
Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
    if (num1 > num2)
        return num2;
    else
        return num1;
}
const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
    if (num1 > num2)
        return num2;
    else
        return num1;
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
    if (num1 < num2)
        return num2;
    else
        return num1;
}
const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
    if (num1 < num2)
        return num2;
    else
        return num1;
}