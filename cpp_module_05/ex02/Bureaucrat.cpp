#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("anonymous"), grade(10)
{
	std::cout << "Bureaucrat : default constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat : destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1) throw GradeTooHighException();
	else if (grade > 150) throw GradeTooLowException();
	else this->grade = grade;
	std::cout << "Bureaucrat : constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "Bureaucrat : copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	throw CopyConstException();
	(void)other;
	return *this;
}

const std::string &Bureaucrat::getName() const {return this->name;}

const int &Bureaucrat::getGrade() const {return this->grade;}

void Bureaucrat::increaseGrade()
{
	int tmp = this->grade;

	--tmp;
	if (tmp < 1) throw GradeTooHighException();
	else {
		std::cout << "the grade was increased from " << this->grade << " to " << tmp << std::endl;
		this->grade = tmp;
	}
}

void Bureaucrat::decreaseGrade()
{
	int tmp = this->grade;

	++tmp;
	if (tmp > 150) throw GradeTooLowException();
	else {
		std::cout << "the grade was decreased from " << this->grade << " to " << tmp << std::endl;
		this->grade = tmp;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << "\033[1;36m" << this->name << "\033[0m" << " signed "
			<< "\033[1;36m" << form.getName() << "\033[0m" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "\033[1;36m" << this->name << "\033[0m" << " couldn't sign "
			<< "\033[1;36m" << form.getName() << "\033[0m" << " because "
			<< e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try {
		form.execute(*this);
		std::cout << "\033[1;36m" << this->name << "\033[0m" << " executed "
			<< "\033[1;36m" << form << "\033[0m" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "\033[1;36m" << this->name << "\033[0m" << " couldn't execute "
			<< "\033[1;36m" << form << "\033[0m" << " because "
			<< e.what() << "." << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the grade is too low";
}

const char* Bureaucrat::CopyConstException::what() const throw()
{
	return "const type is included in the member variables";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "\033[1;36m" << bureaucrat.getName() << "\033[0m" << ", bureaucrat grade "
		<< "\033[1;36m" << bureaucrat.getGrade() << "\033[0m" << ".";
	return out;
}
