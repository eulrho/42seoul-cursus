#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNumber = other.fixedPointNumber;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointNumber = other.fixedPointNumber;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNumber = raw;
}
