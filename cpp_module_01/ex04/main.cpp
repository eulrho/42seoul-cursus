#include <iostream>
#include <string>
#include <fstream>
#include "converter.hpp"

int printError(int error_type)
{
	if (error_type == ERROR_TYPE_INPUT)
		std::cout << "Invalid input value\n";
	else if (error_type == ERROR_TYPE_OPEN)
		std::cout << "Failed to open the file\n";
	else if (error_type == ERROR_TYPE_EMPTY_STRING)
		std::cout << "string is empty\n";
	return (1);
}

void printFile(std::string contents, std::string *str, std::ofstream &fout)
{

	int idx = 0;
	int len = contents.length();

	while (idx < len) {
		std::string::size_type n = contents.find(str[0], idx);

		if (n == std::string::npos) {
			fout << contents.substr(idx);
			return ;
		}
		fout << contents.substr(idx, n - idx);
		fout << str[1];
		idx = n + str[0].length();
	}
}

int readFile(std::string fileName, std::string *str)
{
	std::string newFile = fileName + ".replace";
	std::ifstream fin;
	std::ofstream fout;
	int status = 0;

	fin.open(fileName.c_str());
	fout.open(newFile.c_str());
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
	}
	else
		status = printError(ERROR_TYPE_OPEN);
	if (fin.is_open()) fin.close();
	if (fout.is_open()) fout.close();
	return (status);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (printError(ERROR_TYPE_INPUT));

	std::string fileName(argv[1]);
	std::string str[2] = {argv[2], argv[3]};
	int status = 0;
	
	if (str[0].empty())
		return (printError(ERROR_TYPE_INPUT));
	status = readFile(fileName, str);
	return status;
}
