#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(1);

	std::vector<int>::iterator iter;

	std::cout << "============== ";
	std::cout << "\033[1;34m" << "original" << "\033[0m";
	std::cout << " ==============" << std::endl;
	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << ' ';
	}
	std::cout << std::endl << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "success" << "\033[0m";
	std::cout << " ==============" << std::endl;
	try {
		for (iter = ::easyfind(v, 1); iter != v.end(); iter++) {
			std::cout << *iter << ' ';
		}
		std::cout << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "fail" << "\033[0m";
	std::cout << " ==============" << std::endl;
	try {
		for (iter = ::easyfind(v, 3); iter != v.end(); iter++) {
			std::cout << *iter << ' ';
		}
		std::cout << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
