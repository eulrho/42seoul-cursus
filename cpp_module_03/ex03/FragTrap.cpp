#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap : default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap : copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap : constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0) return ;
	this->energyPoints--;
	std::cout << "\033[1;34m";
	std::cout << "FragTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	std::cout << "FragTrap " << this->name << " has " << this->energyPoints
		<< " energy points left" << std::endl;
	std::cout << "\033[0m";
}

void FragTrap::highFivesGuys()
{
	if (this->hitPoints == 0 || this->energyPoints == 0) return ;
	std::cout << "\033[1;33m";
	std::cout << "Hi guys! Let's do a high five with me" << std::endl;
	std::cout << "\033[0m";
}
