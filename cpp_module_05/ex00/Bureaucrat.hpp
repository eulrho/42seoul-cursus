#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

class Bureaucrat {
	private:
		const std::string name;
		int grade;
		Bureaucrat &operator=(const Bureaucrat&);
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat&);
		const std::string &getName() const;
		const int &getGrade() const;
		void increaseGrade();
		void decreaseGrade();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream&, const Bureaucrat&);

#endif