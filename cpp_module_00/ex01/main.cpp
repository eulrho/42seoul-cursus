#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook phoneBook;

	while (true) {
		std::cout << "Please enter one of the three commands : ADD, SEARCH, EXIT\n";
		getline(std::cin, command);
		if (std::cin.eof() == true)
		{
			std::cout << "Invalid input value\n";
			std::clearerr(stdin);
			std::cin.clear();
			continue ;
		}
		if (command == "ADD")
			phoneBook.addPhoneBook();
		else if (command == "SEARCH") {
			phoneBook.printPhoneBook();
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command\n";
	}
	return 0;
}