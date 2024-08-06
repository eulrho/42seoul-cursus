#include <iostream>
#include "iter.hpp"

int main()
{
	int intArray[4] = {5, 4, 3, 2};
	char charArray[4] = {'a', 'b', 'c', 'd'};

	std::cout << "============== ";
	std::cout << "\033[1;34m" << "before" << "\033[0m";
	std::cout << " ==============" << std::endl;

	std::cout << "intArray: ";
	for (int i=0; i<4; i++) std::cout << intArray[i] << ' ';
	std::cout << std::endl;
	std::cout << "charArray: ";
	for (int i=0; i<4; i++) std::cout << charArray[i] << ' ';
	std::cout << std::endl;

	::iter(intArray, 4, ::add);
	::iter(charArray, 4, ::add);

	std::cout << "============== ";
	std::cout << "\033[1;34m" << "after" << "\033[0m";
	std::cout << " ==============" << std::endl;
	std::cout << "intArray: ";
	for (int i=0; i<4; i++) std::cout << intArray[i] << ' ';
	std::cout << std::endl;
	std::cout << "charArray: ";
	for (int i=0; i<4; i++) std::cout << charArray[i] << ' ';
	std::cout << std::endl;
	return 0;
}
