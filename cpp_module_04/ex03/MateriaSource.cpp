#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i=0; i<4; i++)
		this->materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i=0; i<4; i++) {
		if (this->materias[i] != NULL) delete this->materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other) {
		for (int i=0; i<4; i++) {
			if (this->materias[i] != NULL) delete this->materias[i];
			this->materias[i] = other.materias[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL) return ;
	for (int i=0; i<4; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = m;
			//std::cout << "MateriaSource : " << m->getType() << " is learned" << std::endl;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i=0; i<4; i++) {
		if (this->materias[i] == NULL) continue ;
		if (this->materias[i]->getType() == type) {
			//std::cout << "MateriaSource : " << type << " is created" << std::endl;
			return this->materias[i]->clone();
		}
	}
	return NULL;
}