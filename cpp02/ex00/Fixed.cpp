#include "Fixed.hpp"

Fixed::Fixed(void) : _fixPointNum(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed& fixPointNumCopy) : _fixPointNum(fixPointNumCopy._fixPointNum)
{
    std::cout << "Copy constructor called\n";
}
Fixed &Fixed::operator=(const Fixed& fixPointNumCopy)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &fixPointNumCopy)
        this->_fixPointNum = fixPointNumCopy._fixPointNum;
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixPointNum;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixPointNum = raw;
}