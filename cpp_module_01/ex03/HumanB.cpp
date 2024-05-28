#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << "HumanB : call destructor\n";
}

void HumanB::attack()
{
	if (this->weapon == NULL)
		std::cout << this->name << " doesn't have a weapon." << std::endl;
	else
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {this->weapon = &weapon;}
