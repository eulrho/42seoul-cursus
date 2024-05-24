#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {
	private :
		Weapon* weapon;
		std::string name;
	public :
		HumanB(std::string);
		~HumanB();
		void attack();
		std::string getName() const;
		void setName(std::string);
		Weapon* getWeapon() const;
		void setWeapon(Weapon&);
};

# endif