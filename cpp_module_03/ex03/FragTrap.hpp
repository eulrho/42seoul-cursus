#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap&);
		FragTrap(const std::string &name);
		FragTrap &operator=(const FragTrap &);
		void attack(const std::string& target);
		void highFivesGuys();
};

#endif