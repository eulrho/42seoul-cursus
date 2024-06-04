#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "========== Create ==========" << std::endl;
	ClapTrap *a = new ClapTrap("a");
	ClapTrap *b = new ScavTrap("b");
	ScavTrap *c = new ScavTrap("c");

	std::cout << std::endl;
	std::cout << "========== Attack ==========" << std::endl;
	a->attack("tree");
	b->attack("tree");
	c->attack("tree");
	std::cout << std::endl;
	std::cout << "========== Guard gate ==========" << std::endl;
	//b->guardGate(); // error
	c->guardGate();
	std::cout << std::endl;
	std::cout << "========== Destroy ==========" << std::endl;
	delete a;
	delete b;
	delete c;
	return (0);
}