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
	//Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal* meta[10];

	std::cout << std::endl;
	for (int k=0; k<5; k++) {
		meta[k] = new Dog();
		std::cout << std::endl;
		*meta[k] = *j;
		std::cout << std::endl;
	}
	for (int k=5; k<10; k++) {
		meta[k] = new Cat();
		std::cout << std::endl;
		*meta[k] = *i;
		std::cout << std::endl;
	}
	for (int k=0; k<10; k++)
		std::cout << meta[k]->getType() << std::endl;
	std::cout << std::endl;
	for (int k=0; k<10; k++)
		delete meta[k];
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "=============== Test : brain ===============" << std::endl;
	Cat *a = new Cat();

	std::cout << std::endl;
	a->setBrain("aaa");
	a->setBrain("bbb");
	a->printBrain();
	std::cout << std::endl;
	Cat *b = new Cat(*a);
	std::cout << std::endl;
	a->setBrain("ccc");
	a->printBrain();
	std::cout << std::endl;
	b->setBrain("ddd");
	b->printBrain();
	std::cout << std::endl;
	delete a;
	delete b;
	return 0;
}