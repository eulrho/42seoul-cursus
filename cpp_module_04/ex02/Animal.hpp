#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string &);
		virtual ~Animal();
		Animal(const Animal&);
		Animal &operator=(const Animal &);
		const std::string &getType() const;
		virtual void makeSound() const = 0;
};

#endif