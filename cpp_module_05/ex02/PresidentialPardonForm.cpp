#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm : default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm : destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("presidential pardon", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm : constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << "PresidentialPardonForm : copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm : copy assignment operator called" << std::endl;
	if (this != &other)
		this->target = other.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkExecution(executor.getGrade());
	std::cout << "target " << "\033[1;36m" << this->target << "\033[0m"
			<< " form is running..." << std::endl;
	std::cout << "it has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {return this->target;}
