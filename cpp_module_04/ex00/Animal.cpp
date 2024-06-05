#include <iostream>
#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal : default constructor called" << std::endl;
}

Animal::Animal(std::string &type) : type(type)
{
	std::cout << "Animal : constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal : destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal : copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal : copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

const std::string &Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Animal : ggiiing... ggiing..." << std::endl;
}
