#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap :public FragTrap, public ScavTrap {
	private:
		std::string name;
		DiamondTrap();
	public:
		DiamondTrap(const std::string&);
		virtual ~DiamondTrap();
		DiamondTrap(const DiamondTrap&);
		DiamondTrap &operator=(const DiamondTrap &);
		void attack(const std::string& target);
		void whoAmI();
};

#endif