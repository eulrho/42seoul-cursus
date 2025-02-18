#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;
		bool isEquiped;
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria&);
		AMateria &operator=(const AMateria &);
		std::string const &getType() const;
		bool const &getIsEquiped() const;
		void setIsEquiped(bool);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif