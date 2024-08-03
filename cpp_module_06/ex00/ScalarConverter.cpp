#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
//#include <cstring>
#include <string>
#include <cctype>
#include "ScalarConverter.hpp"
#include "DataType.hpp"

void ScalarConverter::convert(const std::string &target)
{
	try {
		double doubleResult=0.0;
		char charResult;
		int intResult;
		float floatResult=0.0;
		std::string::size_type posD, posF;
		bool isPossible[4] = {true, };

		if (target.empty() || (target.length() != 1 && !std::isdigit(target[0])))
			throw "impossible";
		posD = target.find('.');
		posF = target.find('f', target.length() - 1);
		if (target == "nan" || target == "nanf" || target == "inf" || target == "inff"
			|| target == "-inf" || target == "-inff")
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
		else if (target.length() == 1 && !std::isdigit(target[0])) {
			charResult = static_cast<char>(target[0]);
			intResult = static_cast<int>(charResult);
			floatResult = static_cast<float>(charResult);
			doubleResult = static_cast<double>(charResult);
		}
		else {
			char *endPTR;
			doubleResult = std::strtod(target.c_str(), &endPTR);
			std::string strEndPTR(endPTR);

			if (strEndPTR.length() != 1 || strEndPTR != "f")
				throw "impossible";

			int len = !(posF == std::string::npos);
			len = target.length() - len;


			if (posD == std::string::npos) {

			}
			int i = intResult < 1, tmp = intResult;
			while (tmp) {
				tmp /= 10;
				i++;
			}
			if (i == target.length() || (posF != std::string::npos && i == target.length() - 1))
			{
				if (intResult < CHAR_MIN || intResult > CHAR_MAX)
					isPossible[TYPE_CHAR] = false;
				else charResult = static_cast<char>(intResult);
				floatResult = static_cast<float>(intResult);
				doubleResult = static_cast<double>(intResult);
			}
			else {
				isPossible[TYPE_CHAR] = false;
				isPossible[TYPE_INT] = false;

			}
		}
		charResult = static_cast<char>(doubleResult);
		intResult = static_cast<int>(doubleResult);
		floatResult = static_cast<float>(doubleResult);
		std::cout << "char: " << charResult << std::endl;
		std::cout << "int: " << intResult << std::endl;
		std::cout << "double: " << doubleResult << std::endl;
		std::cout << "float: " << floatResult << std::endl;
	}
	catch(std::string &str) {
		std::cout << "char: " << str << std::endl;
		std::cout << "int: " << str << std::endl;
		std::cout << "double: " << str << std::endl;
		std::cout << "float: " << str << std::endl;
	}
}