#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void leaks()
{
	std::system("leaks ex02");
}

Base *generate(void) {
	Base *base = NULL;

	int randNumber = std::rand() % 3;

	switch (randNumber) {
		case 0:
			base = new A();
			break ;
		case 1:
			base = new B();
			break ;
		case 2:
			base = new C();
			break ;
	}
	return base;
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "this type is " << "\033[1;36m" << "'A'" << "\033[0m" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "this type is " << "\033[1;36m" << "'B'" << "\033[0m" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "this type is " << "\033[1;36m" << "'C'" << "\033[0m" << std::endl;
	else std::cout << "failed to find type" << std::endl;
}

void identify(Base &p) {
	try {
		A &typeA = dynamic_cast<A&>(p);
		(void)typeA;
		std::cout << "this type is " << "\033[1;36m" << "'A'" << "\033[0m" << std::endl;
	}
	catch (std::bad_cast &b) {
		std::cout << b.what() << ", so this type is not 'A'" << std::endl;
		try {
			B &typeB = dynamic_cast<B&>(p);
			(void)typeB;
			std::cout << "this type is " << "\033[1;36m" << "'B'" << "\033[0m" << std::endl;
		}
		catch (std::bad_cast &b) {
			std::cout << b.what() << ", so this type is not 'B'" << std::endl;
			try {
				C &typeC = dynamic_cast<C&>(p);
				(void)typeC;
				std::cout << "this type is " << "\033[1;36m" << "'C'" << "\033[0m" << std::endl;
			}
			catch (std::bad_cast &b) {
				std::cout << b.what() << ", so this type is not 'C'" << std::endl;
			}
		}
	}
}

int main()
{
	//std::atexit(leaks);
	Base *base[4];

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i=0; i<4; i++) base[i] = generate();
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "identify(pointer)" << "\033[0m";
	std::cout << " ==============" << std::endl;
	for (int i=0; i<4; i++) {
		identify(base[i]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "============= ";
	std::cout << "\033[1;34m" << "identify(reference)" << "\033[0m";
	std::cout << " =============" << std::endl;
	for (int i=0; i<4; i++) {
		identify(*base[i]);
		std::cout << std::endl;
	}
	for (int i=0; i<4; i++) delete base[i];
	return 0;
}