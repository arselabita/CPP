#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(4) * Fixed(2));
    Fixed const c(Fixed(4) / Fixed(2));
    Fixed const d(Fixed(5.05f) + Fixed(2));
    Fixed const e(Fixed(5.05f) - Fixed(2));

    std::cout << a << std::endl;

    std::cout << "here ++a: ";
    std::cout << ++a << std::endl;
    std::cout << "after: ";
    std::cout << a << std::endl;

    std::cout << "here a++: ";
    std::cout << a++ << std::endl;
    std::cout << "after: ";
    std::cout << a << std::endl;

    std::cout << "here a--: ";
    std::cout << a-- << std::endl;
    std::cout << "after: ";
    std::cout << a << std::endl;

    std::cout << "here --a: ";
    std::cout << --a << std::endl;
    std::cout << "after: ";
    std::cout << a << std::endl;

    std::cout << "Multiply: ";
    std::cout << b << std::endl;

    std::cout << "Divide: ";
    std::cout << c << std::endl;

    std::cout << "Add: ";
    std::cout << d << std::endl;

    std::cout << "Substract: ";
    std::cout << e << std::endl;

    std::cout << "Max: ";
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "Min: ";
    std::cout << Fixed::min(a, b) << std::endl;

    std::cout << "\n"
              << std::endl;

    Fixed x(10);
    Fixed y(20);
    Fixed z(10);

    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x >= z: " << (x >= z) << std::endl;
    std::cout << "x <= z: " << (x <= z) << std::endl;
    std::cout << "x == z: " << (x == z) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    std::cout << "\n"
              << std::endl;

    Fixed n1(-5);
    Fixed n2(2);

    std::cout << n1 + n2 << std::endl;
    std::cout << n1 - n2 << std::endl;
    std::cout << n1 * n2 << std::endl;
    std::cout << n1 / n2 << std::endl;

    std::cout << "\n"
              << std::endl;

    Fixed f1(1.5f);
    Fixed f2(2.25f);

    std::cout << f1 + f2 << std::endl;
    std::cout << f1 - f2 << std::endl;
    std::cout << f1 * f2 << std::endl;
    std::cout << f1 / f2 << std::endl; // 1.5

    std::cout << "\n"
              << std::endl;

    Fixed g1(5.5f);
    Fixed g2(5.5f);

    std::cout << (g1 == g2) << std::endl;
    std::cout << (g1 != g2) << std::endl;

    std::cout << "\n"
              << std::endl;

    Fixed inc(1);

    std::cout << inc << std::endl;
    std::cout << ++inc << std::endl;
    std::cout << ++inc << std::endl;
    std::cout << inc++ << std::endl;
    std::cout << inc << std::endl;

    std::cout << "\n"
              << std::endl;

    Fixed m1(42);
    Fixed m2(42);

    std::cout << Fixed::min(m1, m2) << std::endl;
    std::cout << Fixed::max(m1, m2) << std::endl;

    std::cout << "\n"
              << std::endl;

    const Fixed c1(12);
    const Fixed c2(8);

    std::cout << Fixed::min(c1, c2) << std::endl;
    std::cout << Fixed::max(c1, c2) << std::endl;

    std::cout << "\n"
              << std::endl;

    Fixed m(2.5f);

    std::cout << (m + Fixed(3)) << std::endl;
    std::cout << (m - Fixed(1)) << std::endl;
    std::cout << (m * Fixed(4)) << std::endl;
    std::cout << (m / Fixed(2)) << std::endl;

    return 0;
}