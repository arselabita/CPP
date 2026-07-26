#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int intValue) : _value(intValue<<_fractBits)
{
    std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float floatValue) : _value(roundf(floatValue*(1<<_fractBits)))
{
    std::cout << "Float constructor called\n";
}
Fixed::Fixed(const Fixed &original) : _value(original.getRawBits())
{
    std::cout << "Copy constructor called\n";
}
Fixed &Fixed::operator=(const Fixed &original)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &original)
        this->_value = original.getRawBits();
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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
    return (float)_value/(1<<_fractBits);
}
int Fixed::toInt(void) const
{
    return _value>>_fractBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}