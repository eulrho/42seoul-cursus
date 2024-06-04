#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap : default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap : copy constructor called" << std::endl;
	*this = other;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap : constructor called" << std::endl;
	this->name = name;
	this->hitPoint = HP_MAX;
	this->energyPoints = EP_MAX;
	this->attackDamage = ATTACK_DAMAGE;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap : copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoint = other.hitPoint;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Hi Guys! Let's do a high five with me" << std::endl;
}
