#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *pstr = &str;
	std::string &rstr = str;

	std::cout << "***** Memory address *****\n";
	std::cout << &str << std::endl;
	std::cout << pstr << std::endl;
	std::cout << &rstr << std::endl;
	std::cout << '\n';

	std::cout << "***** string value *****\n";
	std::cout << str << std::endl;
	std::cout << *pstr << std::endl;
	std::cout << rstr << std::endl;
	return (0);
}