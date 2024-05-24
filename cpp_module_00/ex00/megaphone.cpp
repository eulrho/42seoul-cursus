#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		std::string str_argv = argv[i];
		
		for (int j = 0; j < (int)str_argv.length(); j++)
			std::cout << static_cast<char>(std::toupper(str_argv[j]));
	}
	std::cout << std::endl;
	return (0);
}