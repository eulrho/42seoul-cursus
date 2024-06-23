#include <iostream>
#include "AForm.hpp"

AForm::AForm() : name("anonymous"), isSigned(false), sGrade(10), eGrade(5)
{
	std::cout << "AForm : default constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm : destructor called" << std::endl;
}

AForm::AForm(std::string name, int sGrade, int eGrade) : name(name), isSigned(false), sGrade(sGrade), eGrade(eGrade)
{
	if (this->sGrade < 1) throw GradeTooHighException();
	else if (this->sGrade > 150) throw GradeTooLowException();
	if (this->eGrade < 1) throw GradeTooHighException();
	else if (this->eGrade > 150) throw GradeTooLowException();
	std::cout << "AForm : constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.getName()), isSigned(other.getIsSigned()), sGrade(other.getSGrade()), eGrade(other.getEGrade())
{
	std::cout << "AForm : copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	throw CopyConstException();
	(void)other;
	return *this;
}

const std::string &AForm::getName() const {return this->name;}

const bool &AForm::getIsSigned() const {return this->isSigned;}

const int &AForm::getSGrade() const {return this->sGrade;}

const int &AForm::getEGrade() const {return this->eGrade;}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sGrade)
		this->isSigned = true;
	else throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "the grade is too low";
}

const char* AForm::CopyConstException::what() const throw()
{
	return "const type is included in the member variables";
}

void AForm::execute(Bureaucrat const &executor) const 
{
	std::cout << "executor " << executor.getName() << " is at work" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	std::string tmp;

	if (Aform.getIsSigned() == false) tmp = "false";
	else tmp = "true";
	out << "\033[1;36m" << Aform.getName() << "\033[0m" << ", grade required to sign "
		<< "\033[1;36m" << Aform.getSGrade() << "\033[0m" << ", grade required to execute "
		<< "\033[1;36m" << Aform.getEGrade() << "\033[0m" << ", signature status "
		<< "\033[1;36m" << tmp << "\033[0m" << ".";
	return out;
}
