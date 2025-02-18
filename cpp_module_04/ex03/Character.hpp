#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
		int totalTrashSize;
		int trashIdx;
		AMateria **trashCan;
	public:
		Character();
		Character(std::string const & name);
		Character(const Character &);
		Character &operator=(const Character &);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif