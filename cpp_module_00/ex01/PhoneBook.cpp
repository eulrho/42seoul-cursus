#include <iostream>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	bookSize = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Terminate the program" << std::endl;
}

bool PhoneBook::stringInput(std::string &str)
{
	getline(std::cin, str);
	if (std::cin.eof() == true)
	{
		std::cout << "Invalid input value\n";
		std::clearerr(stdin);
		std::cin.clear();
		return false;
	}
	return true;
}

bool PhoneBook::isSpace(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++) {
		if (std::isspace(str[i]) && str[i] != '\n') {
			std::cout << "Invalid value : " << str << " contain white some spaces" << std::endl;
			return true;
		}
	}
	return false;
}

bool PhoneBook::isDigit(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++) {
		if (!std::isdigit(str[i])) {
			std::cout << "Invalid number : " << str << std::endl;
			return false;
		}
	}
	return true;
}

void PhoneBook::addPhoneBook()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Please enter the first name...\n";
	if (!stringInput(firstName) || isSpace(firstName)) return ;
	std::cout << "Please enter the last name...\n";
	if (!stringInput(lastName) || isSpace(firstName)) return ;
	std::cout << "Please enter the nickname...\n";
	if (!stringInput(nickname) || isSpace(firstName)) return ;
	std::cout << "Please enter the phone number(except for '-')...\n";
	if (!stringInput(phoneNumber) || !isDigit(phoneNumber)) return ;
	std::cout << "Please enter the darkest secret...\n";
	if (!stringInput(darkestSecret) || isSpace(firstName)) return ;
	book[this->index].setFirstName(firstName);
	book[this->index].setLastName(lastName);
	book[this->index].setNickname(nickname);
	book[this->index].setPhoneNumber(phoneNumber);
	book[this->index].setDarkestSecret(darkestSecret);
	this->index = (this->index + 1) % 8;

	if (bookSize < 8)
		this->bookSize += 1;
	std::cout << "Contact added\n";
}

void PhoneBook::printContact(int index)
{
	std::string str;

	std::cout << '|' << std::setw(10) << index << '|';
	str = book[index].getFirstName();
	if (str.length() <= 10)
		std::cout << std::setw(10) << str << '|';
	else std::cout << str.substr(0, 9) << '.' << '|';
	str = book[index].getLastName();
	if (str.length() <= 10)
		std::cout << std::setw(10) << str << '|';
	else std::cout << str.substr(0, 9) << '.' << '|';
	str = book[index].getNickname();
	if (str.length() <= 10)
		std::cout << std::setw(10) << str << '|';
	else std::cout << str.substr(0, 9) << '.' << '|';
	std::cout << std::endl;
}

void PhoneBook::printSearchResult(int index)
{
	std::string str;
	
	std::cout << "[first name] : " << book[index].getFirstName() << std::endl;
	std::cout << "[last name] : " << book[index].getLastName() << std::endl;
	std::cout << "[nickname] : " << book[index].getNickname() << std::endl;
	std::cout << "[phone number] : " << book[index].getPhoneNumber() << std::endl;
	std::cout << "[darkest secret] : " << book[index].getDarkestSecret() << std::endl;
}

void PhoneBook::printPhoneBook()
{
	std::cout << "*********************************************\n";
	std::cout << "│     index│first name│ last name⎟  nickname|\n";
	std::cout << "*********************************************\n";
	for (int i = 0; i < this->bookSize; i++)
		printContact(i);
}

void PhoneBook::searchContact()
{
	std::string index;

	std::cout << "Please enter the index...\n";
	if (!stringInput(index)) return ;
	if (index.length() != 1 || !(index[0] >= '0' && index[0] < this->bookSize + '0'))
	{
		std::cout << "Invalid index : " << index << std::endl;
		return ;
	}
	printSearchResult(index[0] - '0');
}
