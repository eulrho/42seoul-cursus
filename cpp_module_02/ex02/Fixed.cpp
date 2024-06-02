#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int intNumber)
{
	//std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = intNumber << this->fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
	//std::cout << "Float constructor called" << std::endl;
	float newNumber = floatNumber;

	for (int i=0; i<this->fractionalBits; i++)
		newNumber *= 2;
	this->fixedPointNumber = std::roundf(newNumber);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNumber = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->fixedPointNumber > other.fixedPointNumber;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->fixedPointNumber < other.fixedPointNumber;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->fixedPointNumber >= other.fixedPointNumber;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->fixedPointNumber <= other.fixedPointNumber;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->fixedPointNumber == other.fixedPointNumber;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->fixedPointNumber != other.fixedPointNumber;
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed temp(this->toFloat() + other.toFloat());
	return temp;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed temp(this->toFloat() - other.toFloat());
	return temp;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed temp(this->toFloat() * other.toFloat());
	return temp;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed temp(this->toFloat() / other.toFloat());
	return temp;
}

Fixed &Fixed::operator++()
{
	this->fixedPointNumber++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->fixedPointNumber--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--*this;
	return temp;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNumber = raw;
}

float Fixed::toFloat(void) const
{
	float newNumber = static_cast<float>(this->fixedPointNumber);

	for (int i=0; i<this->fractionalBits; i++)
		newNumber /= 2;
	return newNumber;
}

int Fixed::toInt(void) const
{
	return this->fixedPointNumber >> this->fractionalBits;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 < fixed2) return fixed1;
	else return fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2) return fixed1;
	else return fixed2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
