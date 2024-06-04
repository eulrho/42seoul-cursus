#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "========== Create ==========" << std::endl;
	ClapTrap *a = new ClapTrap("a");
	ClapTrap *b = new FragTrap("b");
	FragTrap *c = new FragTrap("c");

	std::cout << std::endl;
	std::cout << "========== Attack ==========" << std::endl;
	a->attack("tree");
	b->attack("tree");
	c->attack("tree");
	std::cout << std::endl;
	std::cout << "========== High five ==========" << std::endl;
	//b->highFivesGuys(); // error
	c->highFivesGuys();
	std::cout << std::endl;
	std::cout << "========== Destroy ==========" << std::endl;
	delete a;
	delete b;
	delete c;
	return (0);
}