#include "Fixed.hpp"

Fixed::Fixed(void) : _fixPointNum(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed& original) : _fixPointNum(original._fixPointNum)
{
    std::cout << "Copy constructor called\n";
}
Fixed &Fixed::operator=(const Fixed& original)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &original)
        this->_fixPointNum = original._fixPointNum;
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixPointNum;
}

void Fixed::setRawBits(int const raw)
{
    _fixPointNum = raw;
}