#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat : default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat : destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat : copy constructor called" << std::endl;
	this->brain = new Brain();
	*(this->brain) = *(other.brain);
	// this->brain = other.brain;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat : copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->brain) = *(other.brain);
		// this->brain = other.brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat : meow... meow..." << std::endl;
}

void Cat::printBrain() const
{
	this->brain->printIdeas();
}

void Cat::setBrain(const std::string &str)
{
	this->brain->setIdeas(str);
}
