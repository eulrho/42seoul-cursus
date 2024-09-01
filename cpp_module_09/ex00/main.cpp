#include <iostream>
#include <vector>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	try {
		if (argc != 2)
			throw BitcoinExchange::FileOpenException();

		BitcoinExchange b;
		b.findAmountOfBitcoin(std::string(argv[1]));
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
