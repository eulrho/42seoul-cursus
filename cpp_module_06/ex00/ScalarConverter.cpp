#include <iostream>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cfloat>
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
	std::string pureTarget;
	std::string::size_type posD, posF;
	bool isPossible[4] = {true, true, true, true};

	posD = target.find('.');
	posF = target.find('f', target.length() - 1);

	// parse
	try {
		size_t i = 0;
		size_t len = target.length();

		while (i < len && isspace(target[i])) i++;
		pureTarget = target.substr(i);

		if (pureTarget.empty()) throw std::string("impossible");

		if (pureTarget == "nan" || pureTarget == "+inf" || pureTarget == "-inf" || pureTarget == "inf")
		{
			double tmp = 0.0;

			if (pureTarget == "nan")
				doubleResult = tmp / 0.0;
			else if (pureTarget[0] == '-')
				doubleResult = -DBL_MAX * 100.0;
			else
				doubleResult = DBL_MAX * 100.0;
			floatResult = static_cast<float>(doubleResult);
			isPossible[TYPE_CHAR] = false;
			isPossible[TYPE_INT] = false;
		}
		else if (pureTarget == "nanf" || pureTarget == "+inff" || pureTarget == "-inff" || pureTarget == "inff")
		{
			float tmp = 0.0f;

			if (pureTarget == "nanf")
				floatResult = tmp / 0.0;
			else if (pureTarget[0] == '-')
				floatResult = -FLT_MAX * 100.0f;
			else
				floatResult = FLT_MAX * 100.0f;
			doubleResult = static_cast<float>(floatResult);
			isPossible[TYPE_CHAR] = false;
			isPossible[TYPE_INT] = false;
		}
		else if (pureTarget.length() == 1 && !std::isdigit(pureTarget[0])) { // char
			charResult = static_cast<char>(pureTarget[0]);
			intResult = static_cast<int>(charResult);
			floatResult = static_cast<float>(charResult);
			doubleResult = static_cast<double>(charResult);
		}
		else if (posD == std::string::npos) { // int
			len -= i;
			i = 0;
			if (i < len && (pureTarget[i] == '-' || pureTarget[i] == '+'))
				i++;

			if (i == len) throw std::string("impossible");
			while (i < len) {
				if (!std::isdigit(pureTarget[i]))
					throw std::string("impossible");
				i++;
			}

			std::stringstream streamToInt(pureTarget);
			streamToInt >> intResult;

			if (streamToInt.fail()) {
				isPossible[TYPE_INT] = false;
				isPossible[TYPE_CHAR] = false;

				char *endPTR;

				floatResult = std::strtof(pureTarget.c_str(), &endPTR);
				if (std::isinf(floatResult))
					doubleResult = std::strtod(pureTarget.c_str(), &endPTR);
				else
					doubleResult = static_cast<double>(floatResult);
			}
			else {
				if (intResult < static_cast<int>(CHAR_MIN) || intResult > static_cast<int>(CHAR_MAX))
					isPossible[TYPE_CHAR] = false;
				else charResult = static_cast<char>(intResult);
				floatResult = static_cast<float>(intResult);
				doubleResult = static_cast<double>(intResult);
			}
		}
		else if (posF != std::string::npos) { // float
			char *endPTR;

			floatResult = std::strtof(pureTarget.c_str(), &endPTR);

			std::string tmp(endPTR);
			if (tmp != "f") throw std::string("impossible");

			if (static_cast<double>(floatResult) < static_cast<double>(CHAR_MIN)
				|| static_cast<double>(floatResult) > static_cast<double>(CHAR_MAX))
				isPossible[TYPE_CHAR] = false;
			else charResult = static_cast<char>(floatResult);
			if (static_cast<double>(floatResult) < static_cast<double>(INT_MIN)
				|| static_cast<double>(floatResult) > static_cast<double>(INT_MAX))
				isPossible[TYPE_INT] = false;
			else intResult = static_cast<int>(floatResult);
			if (std::isinf(floatResult))
				doubleResult = std::strtod(pureTarget.c_str(), &endPTR);
			else
				doubleResult = static_cast<double>(floatResult);
		}
		else { // double
			char *endPTR;

			doubleResult = std::strtod(pureTarget.c_str(), &endPTR);

			std::string tmp(endPTR);
			if (!tmp.empty()) throw std::string("impossible");

			if (doubleResult < static_cast<double>(CHAR_MIN) || doubleResult > static_cast<double>(CHAR_MAX))
				isPossible[TYPE_CHAR] = false;
			else charResult = static_cast<char>(doubleResult);
			if (doubleResult < static_cast<double>(INT_MIN) || doubleResult > static_cast<double>(INT_MAX))
				isPossible[TYPE_INT] = false;
			else intResult = static_cast<int>(doubleResult);
			if (doubleResult < static_cast<double>(-FLT_MAX))
				floatResult = -FLT_MAX * 100.0f;
			else if (doubleResult > static_cast<double>(FLT_MAX))
				floatResult = FLT_MAX * 100.0f;
			else floatResult = static_cast<float>(doubleResult);
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
			if (isinf(floatResult) && pureTarget[0] != '-')
				std::cout << "float: +" << floatResult << 'f' << std::endl;
			else std::cout << "float: " << floatResult << 'f' << std::endl;
		}
		else std::cout << "float: impossible" << std::endl;
		if (isPossible[TYPE_DOUBLE]) {
			if (isinf(doubleResult) && pureTarget[0] != '-')
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
