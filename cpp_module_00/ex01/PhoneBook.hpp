#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		int index;
		int bookSize;
		Contact book[8];
		void printContact(int);
		void printSearchResult(int);
		bool isDigit(std::string);
		bool isSpace(std::string);
		bool stringInput(std::string&);
	public:
		PhoneBook();
		~PhoneBook();
		void addPhoneBook();
		void printPhoneBook();
		void searchContact();
};

#endif