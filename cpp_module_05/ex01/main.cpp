#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void leaks(void)
{
	std::system("leaks ex01");
}

int main()
{
	//std::atexit(leaks);
	try {
		std::cout << "===================== ";
		std::cout << "\033[1;34m" << "test : constructor(sGrade:out of grade)" << "\033[0m";
		std::cout << " =====================" << std::endl;
		Form *form1 = new Form("form1", 151, 3);

		delete form1;
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "===================== ";
		std::cout << "\033[1;34m" << "test : constructor(eGrade:out of grade)" << "\033[0m";
		std::cout << " =====================" << std::endl;
		Form *form2 = new Form("form2", 5, 0);

		delete form2;
	}
	catch(std::exception &ex) {
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=========== ";
	std::cout << "\033[1;34m" << "test : sign" << "\033[0m";
	std::cout << " ===========" << std::endl;
	Bureaucrat *a = new Bureaucrat("a", 3);
	Bureaucrat *b = new Bureaucrat("b", 10);
	Form *form3 = new Form("form3", 3, 3);
	Form *form4 = new Form("form4", 5, 5);

	std::cout << std::endl;
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	std::cout << *form3 << std::endl;
	std::cout << *form4 << std::endl;
	std::cout << "\033[1;33m" << "[success]" << "\033[0m" << std::endl;
	a->signForm(*form3);
	std::cout << *form3 << std::endl;
	std::cout << "\033[1;31m" << "[fail]" << "\033[0m" << std::endl;
	b->signForm(*form4);
	std::cout << *form4 << std::endl;

	std::cout << std::endl;
	delete a;
	delete b;
	delete form3;
	delete form4;
	std::cout << std::endl;
	return 0;
}
