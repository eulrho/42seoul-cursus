#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try {
		if (argc == 1) throw std::invalid_argument(std::string("Error"));

		PmergeMe p;
		p.fordJohnson(argc, argv);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}