#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string&, const int&);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat &operator=(const Bureaucrat&);
		const std::string &getName() const;
		const int &getGrade() const;
		void increaseGrade();
		void decreaseGrade();
		void signForm(AForm &);
		void executeForm(AForm const&);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class CopyConstException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream&, const Bureaucrat&);

#endif