#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		~Contact();
		const std::string getFirstName() const;
		const std::string getLastName() const;
		const std::string getNickname() const;
		const std::string getPhoneNumber() const;
		const std::string getDarkestSecret() const;
		void setFirstName(std::string);
		void setLastName(std::string);
		void setNickname(std::string);
		void setPhoneNumber(std::string);
		void setDarkestSecret(std::string);
};

#endif
