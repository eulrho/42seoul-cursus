#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoint(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap : default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoint(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap : constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap : destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap : copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap : copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoint = other.hitPoint;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0) return ;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->energyPoints
		<< " energy points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint == 0) return ;
	if (this->hitPoint >= amount)
		this->hitPoint -= amount;
	else this->hitPoint = 0;
	this->attackDamage += amount;
	std::cout << "ClapTrap " << this->name << " take damage " << amount << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoint
		<< " hit point left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint == 0 || this->energyPoints == 0) return ;
	unsigned int tmp = this->hitPoint;

	this->energyPoints--;
	if (this->hitPoint + amount >= 10)
		this->hitPoint = 10;
	else
		this->hitPoint += amount;
	std::cout << "ClapTrap " << this->name << " is repaired, increasing hit point from "
		<< tmp << " to " << this->hitPoint << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->energyPoints
		<< " energy points left" << std::endl;
}
