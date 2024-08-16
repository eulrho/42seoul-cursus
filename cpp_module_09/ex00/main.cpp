#include <iostream>
#include <vector>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	try {
		if (argc != 2)
			throw BitcoinExchange::FileOpenException();
		BitcoinExchange b;
		std::string inputFile(argv[1]);

		b.findAmountOfBitcoin(inputFile);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
