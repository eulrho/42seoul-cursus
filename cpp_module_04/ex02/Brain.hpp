#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(std::string &);
		~Brain();
		Brain(const Brain&);
		Brain &operator=(const Brain &);
};

#endif