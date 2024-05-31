#include <iostream>
#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

//	Fixed a;
//	a.setRawBits(1);
//
//	Fixed b(a);
//	std::cout << b.getRawBits() << std::endl;
//	a.setRawBits(2);
//	std::cout << b.getRawBits() << std::endl;
//
//	Fixed c = a;
//	std::cout << c.getRawBits() << std::endl;
//	a.setRawBits(1);
//	std::cout << c.getRawBits() << std::endl;
	return 0;
}