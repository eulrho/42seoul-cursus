#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
// #include <cstdlib>

// void leaks(void)
// {
// 	system("leaks a.out");
// }

int main()
{
	//std::atexit(leaks);
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	if (!tmp->getIsEquiped()) delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	if (!tmp->getIsEquiped()) delete tmp;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);

	delete bob;
	delete me;
	delete src;

	return 0;
}