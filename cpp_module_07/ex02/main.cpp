#include <iostream>
#include <cstdlib>
#include "Array.hpp"

void leaks()
{
	std::system("leaks ex02");
}

int main()
{
	//std::atexit(leaks);

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
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "operator exception" << "\033[0m";
	std::cout << " ==============" << std::endl;
	std::cout << "a[6] = " << a[6] << std::endl;
	return 0;
}