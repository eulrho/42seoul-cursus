#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog&);
		Dog &operator=(const Dog &);
		void makeSound() const;
};

#endif