#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	std::cout << "ShrubberyCreationForm : default constructor called" << std::endl;
	this->target = "anonymous";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm : destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target)
{
	std::cout << "ShrubberyCreationForm : constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm : copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm : copy assignment operator called" << std::endl;
	if (this != &other)
		this->target = other.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string fileName = this->target + "_shrubbery";
	std::ofstream fout;
	
	if (145 < executor.getGrade()) throw GradeTooLowException();
	if (137 < executor.getGrade()) throw GradeTooLowException();

	fout.open(fileName.c_str());
	if (fout.is_open()) {
		fout << "          .     .  .      +     .      .          ." << std::endl;
		fout << "     .       .      .     #       .           ." << std::endl;
		fout << "        .      .         ###            .      .      ." << std::endl;
		fout << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
		fout << "          .      . \"####\"###\"####\"  ." << std::endl;
		fout << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
		fout << "  .             \"#########\"#########\"        .        ." << std::endl;
		fout << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
		fout << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
		fout << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
		fout << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
		fout << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
		fout << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
		fout << "            .     \"      000      \"    .     ." << std::endl;
		fout << "       .         .   .   000     .        .       ." << std::endl;
		fout << ".. .. ..................O000O........................ ...... ..." << std::endl;
	}
	else throw FileOpenException();
	fout.close();
}

const std::string &ShrubberyCreationForm::getTarget() const {return this->target;}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "opening file failed";
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	out << form.getTarget();
	return out;
}
