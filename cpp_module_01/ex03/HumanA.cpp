#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& newWeapon) : weapon(newWeapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
	std::cout << "HumanA : call destructor\n";
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}
