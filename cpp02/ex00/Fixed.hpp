#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed(void);                          // Constructor
    Fixed(const Fixed& fixPointNumCopy);                   // Copy constructor
    Fixed& operator= (const Fixed& fixPointNumCopy);     // Copy assignment operator
    ~Fixed(void);                                        // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _fixPointNum;
    static const int _fractBits;
};

#endif