#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string&);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
		void execute(Bureaucrat const &) const;
		const std::string &getTarget() const;
		class FileOpenException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif