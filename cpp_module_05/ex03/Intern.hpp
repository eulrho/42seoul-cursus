#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern &operator=(const Intern&);
		Form *makeForm(const std::string&, const std::string&);
		class CreateFormException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
