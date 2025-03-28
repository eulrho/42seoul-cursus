#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat&);
		Cat &operator=(const Cat &);
		void makeSound() const;
		void printBrain() const;
		void setBrain(const std::string &str);
};

#endif