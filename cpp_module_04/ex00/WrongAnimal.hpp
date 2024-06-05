#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string &);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal &operator=(const WrongAnimal &);
		const std::string &getType() const;
		void makeSound() const;
};

#endif