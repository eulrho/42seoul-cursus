#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "========== Create ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- ClapTrap]" << "\033[0m" << std::endl;
	ClapTrap *a = new ClapTrap("a");
	std::cout << "\033[1;35m" << "[ClapTrap <- ScavTrap]" << "\033[0m" << std::endl;
	ClapTrap *b = new ScavTrap("b");
	std::cout << "\033[1;35m" << "[ScavTrap <- ScavTrap]" << "\033[0m" << std::endl;
	ScavTrap *c = new ScavTrap("c");

	std::cout << std::endl;
	std::cout << "========== Copy constructor ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- ClapTrap]" << "\033[0m" << std::endl;
	ClapTrap aa = *a;
	aa.status();

	std::cout << "\033[1;35m" << "[ClapTrap <- ScavTrap]" << "\033[0m" << std::endl;
	ClapTrap bb = *b;
	bb.status();

	std::cout << "\033[1;35m" << "[ScavTrap <- ScavTrap]" << "\033[0m" << std::endl;
	ScavTrap cc = *c;
	cc.status();
	std::cout << std::endl;
	std::cout << "========== Copy assignment operator ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ScavTrap <- ScavTrap]" << "\033[0m" << std::endl;
	ScavTrap dd;

	dd = cc;
	dd.status();
	std::cout << std::endl;
	std::cout << "========== Attack ==========" << std::endl;
	a->attack("b");
	b->takeDamage(0);
	b->attack("a");
	a->takeDamage(20);
	c->attack("b");
	b->takeDamage(20);
	std::cout << std::endl;
	std::cout << "========== Test : guardGate ==========" << std::endl;
	//b->guardGate(); // error
	c->guardGate();
	std::cout << std::endl;
	std::cout << "========== Destroy ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- ClapTrap]" << "\033[0m" << std::endl;
	delete a;
	std::cout << "\033[1;35m" << "[ClapTrap <- ScavTrap]" << "\033[0m" << std::endl;
	delete b;
	std::cout << "\033[1;35m" << "[ScavTrap <- ScavTrap]" << "\033[0m" << std::endl;
	delete c;
	std::cout << "\033[1;35m" << "[others]" << "\033[0m" << std::endl;
	return (0);
}