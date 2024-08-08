#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main()
{
	std::cout << "\033[1;33m" << "●●● private test ●●●" << "\033[0m" << std::endl << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "constructor" << "\033[0m";
	std::cout << " ==============" << std::endl;
	Array<int> a(5);
	std::cout << "a = ";
	for (int i=0; i<5; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "copy constructor" << "\033[0m";
	std::cout << " ==============" << std::endl;
	for (int i=0; i<5; i++)
		a[i] = i;
	std::cout << "a = ";
	for (int i=0; i<5; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	Array<int> b = a;
	std::cout << "b = ";
	for (int i=0; i<5; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "copy assignment operator" << "\033[0m";
	std::cout << " ==============" << std::endl;
	Array<int> c(4);
	std::cout << "c = ";
	for (int i=0; i<static_cast<int>(c.size()); i++) {
		std::cout << c[i] << ' ';
	}
	std::cout << std::endl;
	c = a;
	std::cout << "c = ";
	for (int i=0; i<static_cast<int>(c.size()); i++) {
		std::cout << c[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "size" << "\033[0m";
	std::cout << " ==============" << std::endl;
	std::cout << "a = ";
	for (int i=0; i<5; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "size of a = " << a.size() << std::endl;
	std::cout << std::endl;
	// std::cout << "============== ";
	// std::cout << "\033[1;34m" << "operator exception" << "\033[0m";
	// std::cout << " ==============" << std::endl;
	// std::cout << "a[6] = " << a[6] << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;33m" << "●●● public test ●●●" << "\033[0m" << std::endl << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	std::srand(std::time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}
	delete [] mirror;
	return 0;
}