#include <iostream>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <cctype>
#include <cmath>
#include "ScalarConverter.hpp"
#include "DataType.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

void ScalarConverter::convert(const std::string &target)
{
	double doubleResult;
	char charResult;
	int intResult;
	float floatResult;
	std::string::size_type posD, posF;
	bool isPossible[4] = {true, true, true, true};

	posD = target.find('.');
	posF = target.find('f', target.length() - 1);

	// parse
	try {
		if (target.empty()) throw std::string("impossible");

		if (target == "nan" || target == "nanf" || target == "+inf" || target == "+inff"
			|| target == "-inf" || target == "-inff" || target == "inf" || target == "inff")
		{
			double tmp = 0.0;

			if (target == "nan" || target == "nanf")
				doubleResult = tmp / 0.0;
			else if (target[0] == '-')
				doubleResult = -1 / tmp;
			else
				doubleResult = 1 / tmp;
			floatResult = static_cast<float>(doubleResult);
			isPossible[TYPE_CHAR] = false;
			isPossible[TYPE_INT] = false;
		}
		else if (target.length() == 1 && !std::isdigit(target[0])) { // char
			charResult = static_cast<char>(target[0]);
			intResult = static_cast<int>(charResult);
			floatResult = static_cast<float>(charResult);
			doubleResult = static_cast<double>(charResult);
		}
		else if (posD == std::string::npos) { // int
			size_t i = 0;
			size_t len = static_cast<int>(target.length());

			while (i < len && isspace(target[i])) i++;
			if (i < len && (target[i] == '-' || target[i] == '+'))
				i++;
			if (i == len) throw std::string("impossible");
			while (i < len) {
				if (!std::isdigit(target[i]))
					throw std::string("impossible");
				i++;
			}

			std::stringstream streamToInt(target);
			streamToInt >> intResult;

			if (streamToInt.fail()) {
				isPossible[TYPE_INT] = false;
				isPossible[TYPE_CHAR] = false;

				char *endPTR;

				floatResult = std::strtof(target.c_str(), &endPTR);
				if (isinf(floatResult))
					doubleResult = std::strtod(target.c_str(), &endPTR);
				else
					doubleResult = static_cast<double>(floatResult);
			}
			else {
				if (intResult < CHAR_MIN || intResult > CHAR_MAX)
					isPossible[TYPE_CHAR] = false;
				else charResult = static_cast<char>(intResult);
				floatResult = static_cast<float>(intResult);
				doubleResult = static_cast<double>(intResult);
			}
		}
		else if (posF != std::string::npos) { // float
			char *endPTR;

			floatResult = std::strtof(target.c_str(), &endPTR);

			std::string tmp(endPTR);
			if (tmp != "f") throw std::string("impossible");

			if (std::isnan(floatResult)) {
				isPossible[TYPE_CHAR] = false;
				isPossible[TYPE_INT] = false;
				doubleResult = static_cast<double>(floatResult);
			}
			else {
				if (floatResult < CHAR_MIN || floatResult > CHAR_MAX)
					isPossible[TYPE_CHAR] = false;
				else charResult = static_cast<char>(floatResult);
				if (floatResult < INT_MIN || floatResult > INT_MAX)
					isPossible[TYPE_INT] = false;
				else intResult = static_cast<int>(floatResult);
				if (isinf(floatResult))
					doubleResult = std::strtod(target.c_str(), &endPTR);
				else
					doubleResult = static_cast<double>(floatResult);
			}
		}
		else { // double
			char *endPTR;

			doubleResult = std::strtod(target.c_str(), &endPTR);

			std::string tmp(endPTR);
			if (!tmp.empty()) throw std::string("impossible");

			floatResult = static_cast<float>(doubleResult);
			if (std::isnan(doubleResult)) {
				isPossible[TYPE_CHAR] = false;
				isPossible[TYPE_INT] = false;
			}
			else {
				if (doubleResult < CHAR_MIN || doubleResult > CHAR_MAX)
					isPossible[TYPE_CHAR] = false;
				else charResult = static_cast<char>(floatResult);
				if (doubleResult < INT_MIN || doubleResult > INT_MAX)
					isPossible[TYPE_INT] = false;
				else intResult = static_cast<int>(floatResult);
			}
		}

		// print
		if (isPossible[TYPE_CHAR]) {
			if (isprint(charResult))
				std::cout << "char: '" << charResult << "'" << std::endl;
			else std::cout << "char: Non displayable" << std::endl;
		}
		else std::cout << "char: impossible" << std::endl;
		if (isPossible[TYPE_INT])
			std::cout << "int: " << intResult << std::endl;
		else std::cout << "int: impossible" << std::endl;
		if (isPossible[TYPE_FLOAT]) {
			if (isinf(floatResult) && target[0] != '-')
				std::cout << "float: +" << floatResult << 'f' << std::endl;
			else std::cout << "float: " << floatResult << 'f' << std::endl;
		}
		else std::cout << "float: impossible" << std::endl;
		if (isPossible[TYPE_DOUBLE]) {
			if (isinf(doubleResult) && target[0] != '-')
				std::cout << "double: +" << doubleResult << std::endl;
			else std::cout << "double: " << doubleResult << std::endl;
		}
		else std::cout << "double: impossible" << std::endl;
	}
	catch(std::string &str) {
		std::cout << "char: " << str << std::endl;
		std::cout << "int: " << str << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}
