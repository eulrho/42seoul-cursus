#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	try {
		if (argc != 2) throw std::invalid_argument(std::string("Error"));

		RPN rpn;
		std::string str(argv[1]);

		rpn.postfix(str);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
