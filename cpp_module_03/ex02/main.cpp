#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "========== Create ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- ClapTrap]" << "\033[0m" << std::endl;
	ClapTrap *a = new ClapTrap("a");
	a->status();
	std::cout << "\033[1;35m" << "[ClapTrap <- FragTrap]" << "\033[0m" << std::endl;
	ClapTrap *b = new FragTrap("b");
	b->status();
	std::cout << "\033[1;35m" << "[FragTrap <- FragTrap]" << "\033[0m" << std::endl;
	FragTrap *c = new FragTrap("c");
	c->status();

	std::cout << std::endl;
	std::cout << "========== Copy constructor ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- ClapTrap]" << "\033[0m" << std::endl;
	ClapTrap aa = *a;
	aa.status();

	std::cout << "\033[1;35m" << "[ClapTrap <- FragTrap]" << "\033[0m" << std::endl;
	ClapTrap bb = *b;
	bb.status();

	std::cout << "\033[1;35m" << "[FragTrap <- FragTrap]" << "\033[0m" << std::endl;
	FragTrap cc = *c;
	cc.status();
	std::cout << std::endl;
	std::cout << "========== Attack ==========" << std::endl;
	a->attack("b");
	b->attack("a");
	c->attack("b");
	std::cout << std::endl;
	std::cout << "========== Test : highFivesGuys ==========" << std::endl;
	//b->highFivesGuys(); // error
	c->highFivesGuys();
	std::cout << std::endl;
	std::cout << "========== Destroy ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- ClapTrap]" << "\033[0m" << std::endl;
	delete a;
	std::cout << "\033[1;35m" << "[ClapTrap <- FragTrap]" << "\033[0m" << std::endl;
	delete b;
	std::cout << "\033[1;35m" << "[FragTrap <- FragTrap]" << "\033[0m" << std::endl;
	delete c;
	std::cout << "\033[1;35m" << "[others]" << "\033[0m" << std::endl;
	return (0);
}