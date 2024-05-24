#include <iostream>
#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact()
{
	std::cout << "destructor called in contact"  << std::endl;
}

std::string Contact::getFirstName() const {return firstName;}

std::string Contact::getLastName() const {return lastName;}

std::string Contact::getNickname() const {return nickname;}

std::string Contact::getPhoneNumber() const {return phoneNumber;}

std::string Contact::getDarkestSecret() const {return darkestSecret;}

void Contact::setFirstName(std::string firstName) {this->firstName = firstName;}

void Contact::setLastName(std::string lastName) {this->lastName = lastName;}

void Contact::setNickname(std::string nickname) {this->nickname = nickname;}

void Contact::setPhoneNumber(std::string phoneNumber) {this->phoneNumber = phoneNumber;}

void Contact::setDarkestSecret(std::string darkestSecret) {this->darkestSecret = darkestSecret;}
