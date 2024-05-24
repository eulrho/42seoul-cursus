#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private :
		std::string name;
	public :
		Zombie();
		~Zombie(void);
		void announce(void);
		std::string getName(void) const;
		void setName(std::string name);
};

#endif