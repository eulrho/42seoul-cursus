#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

void leaks(void)
{
	std::system("leaks ex00");
}

int main()
{
	//std::atexit(leaks);

	try {
		std::cout << "======================== ";
		std::cout << "\033[1;34m" << "normal case" << "\033[0m";
		std::cout << " =======================" << std::endl;
		Bureaucrat *a = new Bureaucrat("a", 4);
		try {
			std::cout << std::endl;
			std::cout << *a << std::endl;
			a->increaseGrade();
			a->decreaseGrade();

			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << std::endl;
			std::cout << e.what() << std::endl;
		}
		delete a;
	}
	catch(std::exception &e) {
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "============= ";
		std::cout << "\033[1;34m" << "test : constructor (grade = 160)" << "\033[0m";
		std::cout << " =============" << std::endl;
		Bureaucrat *b = new Bureaucrat("b", 160);

		try {
			std::cout << std::endl;
			std::cout << *b << std::endl;
			b->increaseGrade();
			b->decreaseGrade();
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << std::endl;
			std::cout << e.what() << std::endl;
		}
		delete b;
	}
	catch(std::exception &e) {
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "============== ";
		std::cout << "\033[1;34m" << "test : constructor (grade = 0)" << "\033[0m";
		std::cout << " ==============" << std::endl;
		Bureaucrat *c = new Bureaucrat("c", 0);

		try {
			std::cout << std::endl;
			std::cout << *c << std::endl;
			c->increaseGrade();
			c->decreaseGrade();
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << std::endl;
			std::cout << e.what() << std::endl;
		}
		delete c;
	}
	catch(std::exception &e) {
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "=================== ";
		std::cout << "\033[1;34m" << "test : increment fail" << "\033[0m";
		std::cout << " ==================" << std::endl;
		Bureaucrat *d = new Bureaucrat("d", 1);

		try {
			std::cout << std::endl;
			std::cout << *d << std::endl;
			d->increaseGrade();
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << *d << std::endl;
		std::cout << std::endl;
		delete d;
	}
	catch(std::exception &e) {
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "===================";
		std::cout << "\033[1;34m" << " test : decrement fail" << "\033[0m";
		std::cout << " ==================" << std::endl;
		Bureaucrat *e = new Bureaucrat("e", 150);

		try {
			std::cout << std::endl;
			std::cout << *e << std::endl;
			e->decreaseGrade();
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << *e << std::endl;
		std::cout << std::endl;
		delete e;
	}
	catch(std::exception &e) {
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "================";
		std::cout << "\033[1;34m" << " test : copy assign operator" << "\033[0m";
		std::cout << " ===============" << std::endl;
		Bureaucrat *f = new Bureaucrat("f", 150);
		Bureaucrat *g = new Bureaucrat("g", 1);

		try {
			std::cout << std::endl;
			std::cout << *f << std::endl;
			std::cout << *g << std::endl;
			*f = *g;
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << *f << std::endl;
		std::cout << std::endl;
		delete f;
		delete g;
	}
	catch(std::exception &e) {
		std::cout << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}
