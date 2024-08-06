#include <iostream>
#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
	std::cout << "copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
