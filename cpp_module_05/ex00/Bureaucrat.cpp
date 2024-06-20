#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("anonymous"), grade(10)
{
	std::cout << "default constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1) throw GradeTooHighException();
	else if (grade > 150) throw GradeTooLowException();
	else this->grade = grade;
	std::cout << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "copy assignment operator called" << std::endl;
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "\033[1;36m" << bureaucrat.getName() << "\033[0m" << ", bureaucrat grade "
		<< "\033[1;36m" << bureaucrat.getGrade() << "\033[0m" << ".";
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the grade is too low";
}
