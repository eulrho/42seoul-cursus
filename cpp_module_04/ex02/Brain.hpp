#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	private:
		std::string ideas[100];
		unsigned int size;
		unsigned int index;
	public:
		Brain();
		~Brain();
		Brain(const Brain&);
		Brain &operator=(const Brain &);
		void printIdeas() const;
		void setIdeas(const std::string &);
};

#endif