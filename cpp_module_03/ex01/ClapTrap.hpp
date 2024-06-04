#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# define HP_MAX 100
# define EP_MAX 50
# define ATTACK_DAMAGE 20

# include <string>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hitPoint;
		unsigned int energyPoints;
		unsigned int attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string&);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap&);
		ClapTrap &operator=(const ClapTrap &);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif