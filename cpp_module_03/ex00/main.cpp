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
	std::cout << std::endl;
	std::cout << "========== Take damage ==========" << std::endl;
	a.takeDamage(1);
	a.takeDamage(3);
	std::cout << std::endl;
	b.takeDamage(20);
	std::cout << std::endl;
	std::cout << "========== Be repaired ==========" << std::endl;
	a.beRepaired(3);
	a.beRepaired(2);
	std::cout << std::endl;
	b.beRepaired(1);
	std::cout << "========== Energy Test ==========" << std::endl;
	for (int i=0; i<10; i++) {
		std::cout << '[' << i + 1 << ']' << std::endl;
		a.attack("b");
		std::cout << std::endl;
	}
	std::cout << "========== Destroy ==========" << std::endl;
	return (0);
}