#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	//std::cout << this->name << " created\n";
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " : I'll be back....\n";
}

void Zombie::announce(void)
{
	std::cout << this->name << " : " << "BraiiiiiiinnnzzzZ...\n";
}
