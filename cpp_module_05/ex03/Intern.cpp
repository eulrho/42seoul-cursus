#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern : default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern : destructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern : copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern : copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Form *Intern::makeForm(const std::string &name, const std::string &target)
{
	try {
		std::string nameArray[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
		int i = 0;
		Form *result;

		while (i < 3 && nameArray[i] != name)
			i++;
		switch(i) {
			case 0:
				result = new PresidentialPardonForm(target);
				break ;
			case 1:
				result = new RobotomyRequestForm(target);
				break ;
			case 2:
				result = new ShrubberyCreationForm(target);
				break ;
			case 3:
				throw CreateFormException();
		}
		std::cout << "Intern creates " << "\033[1;36m" << name << "\033[0m" << std::endl;
		return (result);
	}
	catch(std::exception &e) {
		std::cout << "Intern fails to create " << "\033[1;36m" << name << "\033[0m"
			<< " because " << e.what() << std::endl;
		return NULL;
	}
}

const char* Intern::CreateFormException::what() const throw()
{
	return "the form does not exist";
}
