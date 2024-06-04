#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap&);
		FragTrap(const std::string &name);
		FragTrap &operator=(const FragTrap &);
		void highFivesGuys();
};

#endif