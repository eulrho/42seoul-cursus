#include <iostream>
#include "Form.hpp"

Form::Form() : name("anonymous"), isSigned(false), sGrade(10), eGrade(5)
{
	std::cout << "Form : default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form : destructor called" << std::endl;
}

Form::Form(std::string name, int sGrade, int eGrade) : name(name), isSigned(false), sGrade(sGrade), eGrade(eGrade)
{
	if (this->sGrade < 1) throw GradeTooHighException();
	else if (this->sGrade > 150) throw GradeTooLowException();
	if (this->eGrade < 1) throw GradeTooHighException();
	else if (this->eGrade > 150) throw GradeTooLowException();
	std::cout << "Form : constructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.getName()), isSigned(other.getIsSigned()), sGrade(other.getSGrade()), eGrade(other.getEGrade())
{
	std::cout << "Form : copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form : copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

const std::string &Form::getName() const {return this->name;}

const bool &Form::getIsSigned() const {return this->isSigned;}

const int &Form::getSGrade() const {return this->sGrade;}

const int &Form::getEGrade() const {return this->eGrade;}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sGrade)
		this->isSigned = true;
	else throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "the grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::string tmp;

	if (form.getIsSigned() == false) tmp = "false";
	else tmp = "true";
	out << "\033[1;36m" << form.getName() << "\033[0m" << ", grade required to sign "
		<< "\033[1;36m" << form.getSGrade() << "\033[0m" << ", grade required to execute "
		<< "\033[1;36m" << form.getEGrade() << "\033[0m" << ", signature status "
		<< "\033[1;36m" << tmp << "\033[0m" << ".";
	return out;
}
