#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap : default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap : copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "ScavTrap : constructor called" << std::endl;
	this->name = name;
	this->hitPoint = HP_MAX;
	this->energyPoints = EP_MAX;
	this->attackDamage = ATTACK_DAMAGE;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap : copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoint = other.hitPoint;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
