#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string&);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm &operator=(const RobotomyRequestForm&);
		void execute(Bureaucrat const &) const;
		const std::string &getTarget() const;
		class RobotomyException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif