#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private :
		Weapon* weapon;
		std::string name;
	public :
		HumanA(std::string, Weapon&);
		~HumanA();
		void attack();
		std::string getName() const;
		void setName(std::string);
		Weapon* getWeapon() const;
		void setWeapon(Weapon);
};

# endif