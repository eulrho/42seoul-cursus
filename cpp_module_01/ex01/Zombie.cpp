#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie(void) {
	std::cout << this->name << " : I'll be back....\n";
}

void Zombie::announce(void)
{
	std::cout << this->name << " : " << "BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {this->name = name;}