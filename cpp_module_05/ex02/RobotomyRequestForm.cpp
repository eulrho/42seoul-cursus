#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("anonymous")
{
	std::cout << "RobotomyRequestForm : default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm : destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target(target)
{
	std::cout << "RobotomyRequestForm : constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm : copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm : copy assignment operator called" << std::endl;
	if (this != &other)
		this->target = other.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int randNumber;

	if (72 < executor.getGrade()) throw GradeTooLowException();
	if (45 < executor.getGrade()) throw GradeTooLowException();
	
	std::cout << "drrrr....drrr...." << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	randNumber = std::rand() % 2;
	if (randNumber == 0) throw RobotomyException();
	else
		std::cout << "it has been robotomized successfully 50% of the time" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const {return this->target;}

const char* RobotomyRequestForm::RobotomyException::what() const throw()
{
	return "the robotomy failed";
}
