#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target("anonymous")
{
	std::cout << "PresidentialPardonForm : default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm : destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target)
{
	std::cout << "PresidentialPardonForm : constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
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
	if (25 < executor.getGrade()) throw GradeTooLowException();
	if (5 < executor.getGrade()) throw GradeTooLowException();

	std::cout << "it has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {return this->target;}
