#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int sGrade;
		const int eGrade;
		Form &operator=(const Form&);
	public:
		Form();
		~Form();
		Form(std::string, int, int);
		Form(const Form&);
		const std::string &getName() const;
		const bool &getIsSigned() const;
		const int &getSGrade() const;
		const int &getEGrade() const;
		void beSigned(const Bureaucrat&);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream&, const Form&);

#endif