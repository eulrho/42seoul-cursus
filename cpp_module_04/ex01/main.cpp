#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
// #include <cstdlib>

// void leaks(void)
// {
// 	system("leaks ex01");
// }

int main()
{
	// std::atexit(leaks);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal* meta[10];

	std::cout << std::endl;
	for (int k=0; k<5; k++) {
		meta[k] = new Dog();
		*meta[k] = *j;
	}
	for (int k=5; k<10; k++) {
		meta[k] = new Cat();
		*meta[k] = *i;
	}
	std::cout << std::endl;
	for (int k=0; k<10; k++)
		std::cout << meta[k]->getType() << std::endl;
	std::cout << std::endl;
	for (int k=0; k<10; k++)
		delete meta[k];
	delete j;
	delete i;

	// std::cout << std::endl;
	// std::cout << "=============== Test : brain ===============" << std::endl;
	// Cat *a = new Cat();
	// Cat *b = new Cat(*a);

	// delete a;
	// delete b;
	return 0;
}