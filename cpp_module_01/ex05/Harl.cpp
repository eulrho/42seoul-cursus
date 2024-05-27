#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl()
{
	std::cout << "destructor called" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "debug level output" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info level output" << std::endl;
}

void Harl::warning(void)
{
	std:: cout << "warning level output" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error level output" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i=0; i<4; i++) {
		if (level == levels[i]) {
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Invalid level" << std::endl;
}
