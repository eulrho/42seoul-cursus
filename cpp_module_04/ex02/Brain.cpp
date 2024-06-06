#include <iostream>
#include "Brain.hpp"

Brain::Brain() : size(0), index(0)
{
	std::cout << "Brain : default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain : destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain : copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain : copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->index = other.index;
		this->size = other.size;
		for (unsigned int i=0; i<this->size; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::printIdeas() const
{
	for (unsigned int i=0; i<this->size; i++)
		std::cout << this->ideas[i] << std::endl;
}

void Brain::setIdeas(const std::string &str)
{
	this->ideas[this->index] = str;
	this->index = this->index + 1 == 100 ? 0 : index + 1;
	this->size = this->size == 100 ? this->size : this->size + 1;
}
