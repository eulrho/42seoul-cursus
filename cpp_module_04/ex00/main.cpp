#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << "============= Test : WrongAnimal =============" << std::endl;
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* m = new WrongCat();

	std::cout << std::endl;
	std::cout << m->getType() << " " << std::endl;
	m->makeSound();
	k->makeSound();
	
	std::cout << std::endl;
	delete k;
	delete m;
	return 0;
}