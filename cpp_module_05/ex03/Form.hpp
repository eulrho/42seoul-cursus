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
	public:
		Form();
		virtual ~Form();
		Form(const std::string&, const int&, const int&);
		Form(const Form&);
		Form &operator=(const Form&);
		const std::string &getName() const;
		const bool &getIsSigned() const;
		const int &getSGrade() const;
		const int &getEGrade() const;
		virtual void beSigned(const Bureaucrat&);
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
		class IsSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
		virtual void execute(Bureaucrat const &) const = 0;
		void checkExecution(const int) const;
};

std::ostream &operator<<(std::ostream&, const Form&);

#endif