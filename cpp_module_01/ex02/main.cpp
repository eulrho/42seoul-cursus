#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "***** Memory address *****\n";
	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "\n***** string value *****\n";
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	// std::cout << "\n***** another test *****\n";
	// std::string tmp = "test";
	// stringREF = tmp;
	// std::cout << &tmp << std::endl;
	// std::cout << &stringREF << std::endl;
	// std::cout << stringREF << std::endl;
	// std::cout << str << std::endl;
	return (0);
}