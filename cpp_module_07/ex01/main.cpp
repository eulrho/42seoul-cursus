#include "iter.hpp"

int main()
{
	int intArray[4] = {5, 4, 3, 2};
	char charArray[4] = {'a', 'b', 'c', 'd'};

	std::cout << "intArray: ";
	for (int i=0; i<4; i++) std::cout << intArray[i] << ' ';
	std::cout << std::endl;
	std::cout << "charArray: ";
	for (int i=0; i<4; i++) std::cout << charArray[i] << ' ';
	std::cout << std::endl;

	std::cout << "============== ";
	std::cout << "\033[1;34m" << "test : print" << "\033[0m";
	std::cout << " ==============" << std::endl;
	::iter(intArray, 4, ::print);
	::iter(charArray, 4, ::print);
	return 0;
}
