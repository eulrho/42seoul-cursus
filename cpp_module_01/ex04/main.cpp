#include <iostream>
#include <string>
#include <fstream>
#include "Converter.hpp"

int printError(int error_type)
{
	if (error_type == ERROR_TYPE_INPUT)
		std::cout << "Invalid input value\n";
	else if (error_type == ERROR_TYPE_OPEN)
		std::cout << "Failed to open the file\n";
	return (1);
}

void printFile(std::string contents, std::string *str, std::ofstream &fout)
{
	std::string *pcontents = &contents;
	int len = contents.length();
	int index = 0;

	while (index < contents.length()) {
		std::string::size_type n = pcontents->find(str[0]);
		
		if (n == std::string::npos) {
			fout << *pcontents;
		}
		std::cout << result << '\n';
	}
	
}

int readFile(std::string fileName, std::string *str)
{
	std::string newFile = fileName + ".replace";
	std::ifstream fin(fileName);
	std::ofstream fout(newFile);
	int status = 0;

	if (fin.is_open() && fout.is_open()) {
		std::string tmp;

		getline(fin, tmp);
		if (fin) {
			printFile(tmp, str, fout);
			while (true) {
				getline(fin, tmp);
				if (!fin) break ;
				else fout << std::endl;
				printFile(tmp, str, fout);
			}
		}
		if (str1 == "") fout << str2;
	}
	else
		status = printError(ERROR_TYPE_OPEN);
	if (fin.is_open()) fin.close();
	if (fout.is_open()) fout.close();
	return (status);
}

int main(int argc, char *argv[])
{
	std::string fileName(argv[1]);
	std::string newFile = fileName + ".replace";
	std::string str[2] = {argv[2], argv[3]};
	std::ifstream fin(fileName);
	std::ofstream fout(newFile);
	int status = 0;

	if (argc != 4)
		return (printError(ERROR_TYPE_INPUT));
	if (str[0].empty())
	return 0;
}
