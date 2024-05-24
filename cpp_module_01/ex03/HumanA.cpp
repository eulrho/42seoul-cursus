#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}

std::string HumanA::getName() const {return name;}

void HumanA::setName(std::string name) {this->name = name;}

Weapon* HumanA::getWeapon() const {return weapon;}

void HumanA::setWeapon(Weapon weapon) {this->weapon = &weapon;}
