#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap : constructor called" << std::endl;
	this->name = this->ClapTrap::name;
	FragTrap tmp;
	this->hitPoints = tmp.getHitPoints();
	this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = tmp.getAttackDamage();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap : destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap : copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap : copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << this->name << ", ClapTrap name : " << this->ClapTrap::name << std::endl;
}