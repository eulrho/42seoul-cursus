#include <iostream>
//#include "ScalarConverter.hpp"
#include <cstdlib>
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
	// std::string target(argv[1]);

	// ScalarConverter::convert(target);
	std::string tmp = "2247483649324333333333333333";
	char *endPTR;
	double d;

	d = std::strtod(tmp.c_str(), &endPTR);
	std::cout << d << std::endl;
	return 0;
}
