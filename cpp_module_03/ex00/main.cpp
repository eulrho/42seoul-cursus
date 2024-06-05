#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main()
{
	std::cout << "========== Create ==========" << std::endl;
	ClapTrap a("a");
	ClapTrap b("b");

	std::cout << std::endl;
	std::cout << "========== Attack ==========" << std::endl;
	a.attack("b");
	b.takeDamage(0);
	std::cout << std::endl;
	std::cout << "========== Test : beRepaired ==========" << std::endl;
	a.takeDamage(1);
	a.takeDamage(4);
	a.beRepaired(3);
	a.beRepaired(2);
	std::cout << std::endl;
	b.beRepaired(1);
	std::cout << std::endl;
	std::cout << "========== Test : Hit points ==========" << std::endl;
	b.takeDamage(20);
	std::cout << std::endl;
	b.takeDamage(20);
	std::cout << std::endl;
	b.attack("a");
	b.beRepaired(3);
	std::cout << "========== Test : Energy points ==========" << std::endl;
	for (int i=0; i<7; i++) {
		a.attack("b");
		std::cout << std::endl;
	}
	a.takeDamage(1);
	a.beRepaired(3);
	a.attack("b");
	std::cout << "========== Destroy ==========" << std::endl;
	return (0);
}