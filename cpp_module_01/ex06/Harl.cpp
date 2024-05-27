#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl()
{
	// std::cout << "destructor called" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "debug level output" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "info level output" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std:: cout << "warning level output" << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "error level output" << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	
	while (i < 4 && levels[i] != level)
		i++;
	switch(i) {
		case 0:
			debug();
			/* FALLTHRU */
		case 1:
			info();
			/* FALLTHRU */
		case 2:
			warning();
			/* FALLTHRU */
		case 3:
			error();
			/* FALLTHRU */
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
