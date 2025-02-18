#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "========== Create ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- FragTrap]" << "\033[0m" << std::endl;
	ClapTrap *a = new FragTrap("a");
	a->status();
	std::cout << "\033[1;35m" << "[ClapTrap <- ScavTrap]" << "\033[0m" << std::endl;
	ClapTrap *b = new ScavTrap("b");
	b->status();
	std::cout << "\033[1;35m" << "[ClapTrap <- DiamondTrap]" << "\033[0m" << std::endl;
	ClapTrap *c = new DiamondTrap("c");
	c->status();
	std::cout << "\033[1;35m" << "[DiamondTrap <- DiamondTrap]" << "\033[0m" << std::endl;
	DiamondTrap *d = new DiamondTrap("d");
	d->status();

	std::cout << std::endl;
	std::cout << "========== Attack ==========" << std::endl;
	a->attack(b->getName());
	b->takeDamage(a->getAttackDamage());
	b->attack(a->getName());
	a->takeDamage(b->getAttackDamage());
	c->attack(b->getName());
	b->takeDamage(c->getAttackDamage());

	std::cout << std::endl;
	std::cout << "========== Test : whoAmI ==========" << std::endl;
	d->whoAmI();
	std::cout << std::endl;
	std::cout << "========== Destroy ==========" << std::endl;
	std::cout << "\033[1;35m" << "[ClapTrap <- FragTrap]" << "\033[0m" << std::endl;
	delete a;
	std::cout << "\033[1;35m" << "[ClapTrap <- ScavTrap]" << "\033[0m" << std::endl;
	delete b;
	std::cout << "\033[1;35m" << "[ClapTrap <- DiamondTrap]" << "\033[0m" << std::endl;
	delete c;
	std::cout << "\033[1;35m" << "[DiamondTrap <- DiamondTrap]" << "\033[0m" << std::endl;
	delete d;
	return (0);
}