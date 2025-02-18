#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() : type("empty"), isEquiped(false) {}

AMateria::AMateria(std::string const &type) : type(type), isEquiped(false) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &other) { *this = other; }

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other) {
		this->type = other.type;
		this->isEquiped = other.isEquiped;
	}
	return *this;
}

std::string const &AMateria::getType() const { return this->type; }

bool const &AMateria::getIsEquiped() const { return this->isEquiped; }

void AMateria::setIsEquiped(bool flag) { this->isEquiped = flag; }

AMateria* AMateria::clone() const { return NULL; }

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria : " << target.getName() << " use " << this->type << std::endl;
}