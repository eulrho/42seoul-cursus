#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# define HP_MAX 10
# define EP_MAX 10
# define ATTACK_DAMAGE 0

# include <string>

class ClapTrap {
	private:
		std::string name;
		unsigned int hitPoint;
		unsigned int energyPoints;
		unsigned int attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string&);
		~ClapTrap();
		ClapTrap(const ClapTrap&);
		ClapTrap &operator=(const ClapTrap &);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif