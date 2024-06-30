#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void leaks(void)
{
	std::system("leaks ex02");
}

int main()
{
	//std::atexit(leaks);

	std::cout << "===================== ";
	std::cout << "\033[1;34m" << "test : ShrubberyCreationForm" << "\033[0m";
	std::cout << " =====================" << std::endl;
	AForm *form1 = new ShrubberyCreationForm("type_A");
	Bureaucrat *a = new Bureaucrat("a", 140);
	Bureaucrat *b = new Bureaucrat("b", 130);
	std::cout << std::endl;

	std::cout << *form1 << std::endl;
	try {
		std::cout << *a << std::endl;
		a->signForm(*form1);
		a->executeForm(*form1);
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}
	try {
		std::cout << *b << std::endl;
		b->executeForm(*form1);
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}
	
	std::cout << std::endl;
	delete form1;
	delete a;
	delete b;

	std::cout << std::endl;
	std::cout << "===================== ";
	std::cout << "\033[1;34m" << "test : RobotomyRequestForm" << "\033[0m";
	std::cout << " =====================" << std::endl;
	AForm *form2 = new RobotomyRequestForm("type_B");
	Bureaucrat *c = new Bureaucrat("c", 80);
	Bureaucrat *d = new Bureaucrat("d", 10);
	std::cout << std::endl;

	std::cout << *form2 << std::endl;
	try {
		std::cout << *c << std::endl;
		c->executeForm(*form2);
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}
	try {
		std::cout << *d << std::endl;
		d->signForm(*form2);
		d->executeForm(*form2);
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}
	
	std::cout << std::endl;
	delete form2;
	delete c;
	delete d;

	std::cout << std::endl;
	std::cout << "===================== ";
	std::cout << "\033[1;34m" << "test : PresidentailPardonForm" << "\033[0m";
	std::cout << " =====================" << std::endl;
	AForm *form3 = new PresidentialPardonForm("type_C");
	Bureaucrat *e = new Bureaucrat("e", 10);
	Bureaucrat *f = new Bureaucrat("f", 1);
	std::cout << std::endl;

	std::cout << *form3 << std::endl;
	try {
		std::cout << *e << std::endl;
		e->executeForm(*form3);
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}
	try {
		std::cout << *f << std::endl;
		f->signForm(*form3);
		f->executeForm(*form3);
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}
	
	std::cout << std::endl;
	delete form3;
	delete e;
	delete f;
	return 0;
}
