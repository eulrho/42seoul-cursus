#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <stdexcept>
# include <string>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> data;
		bool isValidDate(const std::string &);
		bool isValidYear(const std::string &, bool &);
		bool isValidMonth(const std::string &, bool &, bool &);
		bool isValidDay(const std::string &, const bool &, const bool &, const bool &);
		float extractRate(std::string &);
		float extractValue(std::string &);
		void insertData(const std::string &);
		void printAmountOfBitcoin(const std::string &);
		float findRate(const std::string &);
		class TooLargeException : public std::exception {
			public:
				const char* what() const throw();
		};
		class NegativeNumberException : public std::exception {
			public:
				const char* what() const throw();
		};
		class DateNotFoundException : public std::exception {
			public:
				const char* what() const throw();
		};
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange &operator=(const BitcoinExchange&);
		void findAmountOfBitcoin(const std::string &);
		class FileOpenException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif