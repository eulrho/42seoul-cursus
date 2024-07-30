#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45)
{
	std::cout << "RobotomyRequestForm : default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm : destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm : constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
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
	
	this->checkExecution(executor.getGrade());
	std::cout << "target " << "\033[1;36m" << this->target << "\033[0m"
		<< " form is running..." << std::endl;
	std::cout << "drrrr....drrr...." << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	randNumber = std::rand() % 2;
	if (randNumber == 0) throw RobotomyException();
	std::cout << "it has been robotomized successfully 50% of the time" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const {return this->target;}

const char* RobotomyRequestForm::RobotomyException::what() const throw()
{
	return "the robotomy failed";
}
