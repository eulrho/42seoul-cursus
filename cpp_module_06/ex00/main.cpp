#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 0;
	}

	std::cout << std::fixed;
	std::cout.precision(1);
	std::string target(argv[1]);

	ScalarConverter::convert(target);
	return 0;
}
