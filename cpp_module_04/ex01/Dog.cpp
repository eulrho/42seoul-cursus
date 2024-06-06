#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog : default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog : destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog : copy constructor called" << std::endl;
	this->brain = new Brain();
	*(this->brain) = *(other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog : copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->brain) = *(other.brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog : bark... bark..." << std::endl;
}
