#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "MutantStack" << "\033[0m";
	std::cout << " ==============" << std::endl;
	MutantStack<int> a;

	for (int i=0; i<5; i++) a.push(i);

	std::cout << "a = ";
	for (MutantStack<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "list" << "\033[0m";
	std::cout << " ==============" << std::endl;
	std::list<int> b;

	for (int i=0; i<5; i++) b.push_back(i);

	std::cout << "b = ";
	for (std::list<int>::iterator iter = b.begin(); iter != b.end(); iter++) {
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	return 0;
}