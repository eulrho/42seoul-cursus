#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("anonymous"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap : default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
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
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0) return ;
	this->energyPoints--;
	std::cout << "\033[1;34m";
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->energyPoints
		<< " energy points left" << std::endl;
	std::cout << "\033[0m";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0) return ;
	if (this->hitPoints >= amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
	this->attackDamage += amount;
	std::cout << "\033[1;31m";
	std::cout << "ClapTrap " << this->name << " take damage " << amount << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints
		<< " hit points left" << std::endl;
	std::cout << "\033[0m";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0) return ;
	unsigned int tmp = this->hitPoints;

	this->energyPoints--;
	if (this->hitPoints + amount >= 10)
		this->hitPoints = 10;
	else
		this->hitPoints += amount;
	std::cout << "\033[1;32m";
	std::cout << "ClapTrap " << this->name << " is repaired, increasing hit point from "
		<< tmp << " to " << this->hitPoints << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->energyPoints
		<< " energy points left" << std::endl;
	std::cout << "\033[0m";
}

void ClapTrap::status()
{
	std::cout << "\033[1;36m";
	std::cout << "name : " << this->name << std::endl;
	std::cout << "hit points : " << this->hitPoints << std::endl;
	std::cout << "energy points : " << this->energyPoints << std::endl;
	std::cout << "attack damage : " << this->attackDamage << std::endl;
	std::cout << "\033[0m";
}

const unsigned int &ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}
