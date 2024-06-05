#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap : default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap : copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap : constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap : copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0) return ;
	this->energyPoints--;
	std::cout << "\033[1;34m";
	std::cout << "ScavTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	std::cout << "ScavTrap " << this->name << " has " << this->energyPoints
		<< " energy points left" << std::endl;
	std::cout << "\033[0m";
}

void ScavTrap::guardGate()
{
	std::cout << "\033[1;33m";
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
	std::cout << "\033[0m";
}
