#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie(void) {
	std::cout << getName() << " : I'll be back....\n";
}

void Zombie::announce(void)
{
	std::cout << getName() << " : " << "BraiiiiiiinnnzzzZ...\n";
}
std::string Zombie::getName(void) const {return name;}

void Zombie::setName(std::string name) {this->name = name;}