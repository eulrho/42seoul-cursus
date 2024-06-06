#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <string>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string&);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap&);
		ClapTrap &operator=(const ClapTrap &);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status();
		const unsigned int &getAttackDamage() const;
		const std::string &getName() const;
};

#endif