#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "============== ";
	std::cout << "\033[1;34m" << "normal test" << "\033[0m";
	std::cout << " ==============" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "exception test" << "\033[0m";
	std::cout << " ==============" << std::endl;

	std::cout << "\033[1;33m" << "●●● addNumber ●●●" << "\033[0m" << std::endl << std::endl;
	try {
		sp.addNumber(1);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;33m" << "●●● shortestSpan ●●●" << "\033[0m" << std::endl << std::endl;
	Span sp2 = Span(5);
	
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;33m" << "●●● longestSpan ●●●" << "\033[0m" << std::endl << std::endl;
	
	try {
		sp2.addNumber(1);
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "============== ";
	std::cout << "\033[1;34m" << "addNumberRange test" << "\033[0m";
	std::cout << " ==============" << std::endl;

	Span sp3 = Span(3);
	Span sp4 = Span(10000);
	
	try {
		sp3.addNumberRange(4);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp4.addNumberRange(10000);
		//sp4.addNumberRange(10);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
