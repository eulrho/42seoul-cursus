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
	Animal* meta[10];

	for (int k=0; k<5; k++) {
		meta[k] = new Dog();
		std::cout << std::endl;
	}
	for (int k=5; k<10; k++) {
		meta[k] = new Cat();
		std::cout << std::endl;
	}
	for (int k=0; k<10; k++)
		std::cout << meta[k]->getType() << std::endl;
	std::cout << std::endl;
	for (int k=0; k<10; k++) {
		delete meta[k];
		std::cout << std::endl;
	}

	std::cout << "=============== Test : brain of cat ===============" << std::endl;
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

	std::cout << std::endl;
	std::cout << "=============== Test : brain of dog ===============" << std::endl;
	Dog *c = new Dog();

	std::cout << std::endl;
	c->setBrain("aaa");
	c->setBrain("bbb");
	c->printBrain();
	std::cout << std::endl;
	Dog *d = new Dog(*c);
	std::cout << std::endl;
	c->setBrain("ccc");
	c->printBrain();
	std::cout << std::endl;
	d->setBrain("ddd");
	d->printBrain();
	std::cout << std::endl;
	delete c;
	delete d;
	return 0;
}