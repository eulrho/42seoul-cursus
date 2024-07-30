#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

void leaks(void)
{
	std::system("leaks ex03");
}

int main()
{
	//std::atexit(leaks);

	Intern someRandomIntern;

	std::cout << std::endl;
	std::cout << "===================== ";
	std::cout << "\033[1;34m" << "test : ShrubberyCreationForm" << "\033[0m";
	std::cout << " =====================" << std::endl;
	Form *form1;

	form1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << std::endl;
	if (form1) delete form1;
	
	std::cout << std::endl;
	std::cout << "===================== ";
	std::cout << "\033[1;34m" << "test : RobotomyRequestForm" << "\033[0m";
	std::cout << " =====================" << std::endl;
	Form *form2;

	form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;
	if (form2) delete form2;

	std::cout << std::endl;
	std::cout << "===================== ";
	std::cout << "\033[1;34m" << "test : PresidentialPardonForm" << "\033[0m";
	std::cout << " =====================" << std::endl;
	Form *form3;

	form3 = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << std::endl;
	if (form3) delete form3;

	std::cout << std::endl;
	std::cout << "===================== ";
	std::cout << "\033[1;34m" << "test : Wrong case" << "\033[0m";
	std::cout << " =====================" << std::endl;
	Form *form4;

	form4 = someRandomIntern.makeForm("aaa", "Bender");
	std::cout << std::endl;
	if (form4) delete form4;
	return 0;
}
