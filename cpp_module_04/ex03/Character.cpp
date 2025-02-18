#include <iostream>
#include "Character.hpp"

Character::Character() : name("empty"), totalTrashSize(1024), trashIdx(0)
{
	for (int i=0; i<4; i++)
		this->inventory[i] = NULL;
	this->trashCan = new AMateria*[this->totalTrashSize];
}

Character::Character(std::string const &name) : name(name), totalTrashSize(1024), trashIdx(0)
{
	for (int i=0; i<4; i++)
		this->inventory[i] = NULL;
	this->trashCan = new AMateria*[this->totalTrashSize];
}

Character::~Character()
{
	for (int i=0; i<4; i++) {
		if (this->inventory[i] != NULL) delete this->inventory[i];
	}
	for (int i=0; i<this->trashIdx; i++)
		delete this->trashCan[i];
	delete this->trashCan;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other) {
		this->name = other.name;
		for (int i=0; i<4; i++) {
			if (this->inventory[i] != NULL) delete this->inventory[i];
			this->inventory[i] = other.inventory[i]->clone();
		}
		for (int i=0; i<this->trashIdx; i++)
			delete this->trashCan[i];
		delete this->trashCan;

		this->trashIdx = other.trashIdx;
		this->totalTrashSize = other.totalTrashSize;
		this->trashCan = new AMateria*[this->totalTrashSize];
		for (int i=0; i<this->trashIdx; i++)
			this->trashCan[i] = other.trashCan[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const { return this->name; }

void Character::equip(AMateria* m)
{
	if (m == NULL) return ;
	for (int i=0; i<4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			m->setIsEquiped(true);
			//std::cout << "Character : " << this->name << " equip " << this->inventory[i]->getType() << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL) return ;
	//std::cout << "Character : " << this->name << " unequiped " << this->inventory[idx]->getType() << std::endl;
	
	this->trashCan[this->trashIdx++] = this->inventory[idx];
	this->inventory[idx] = NULL;

	if (trashIdx == totalTrashSize) {
		this->totalTrashSize += 1024;
		AMateria **newTrashCan = new AMateria*[this->totalTrashSize];
		for (int i=0; i<this->trashIdx; i++)
			newTrashCan[i] = this->trashCan[i];
		delete this->trashCan;
		this->trashCan = newTrashCan;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL) return ;
	this->inventory[idx]->use(target);
}