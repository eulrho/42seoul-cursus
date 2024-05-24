#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int N = 10;
	Zombie* zombies = zombieHorde(N, "test");

	for (int i=0; i<N; i++) {
		std::cout << '[' << i << ']' << ' ';
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}