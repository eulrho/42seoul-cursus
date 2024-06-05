#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap&);
		ScavTrap(const std::string &name);
		ScavTrap &operator=(const ScavTrap &);
		void attack(const std::string& target);
		void guardGate();
};

#endif