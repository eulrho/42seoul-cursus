#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::attack()
{
	std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}

std::string HumanB::getName() const {return name;}

void HumanB::setName(std::string name) {this->name = name;}

Weapon* HumanB::getWeapon() const {return weapon;}

void HumanB::setWeapon(Weapon& weapon) {this->weapon = &weapon;}
