#include <iostream>
#include <sstream>
#include <algorithm>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) {
		this->sortedVector = std::vector<int>(other.sortedVector);
		this->sortedList = std::list<int>(other.sortedList);
		this->timeOfVector = other.timeOfVector;
		this->timeOfList = other.timeOfList;
	}
	return *this;
}

void PmergeMe::fordJohnson(int argc, char **argv)
{
	insertData(argc, argv);
	std::cout << "Before:	";
	printData();
	this->timeOfVector = sortVector();
	this->timeOfList = sortList();
	std::cout << "After:	";
	printData();
	std::cout << "Time to process a range of	" << argc - 1
		<< " elements with std::vector :	" << this->timeOfVector << " ms" << std::endl;
	std::cout << "Time to process a range of	" << argc - 1
		<< " elements with std::list :	" << this->timeOfList << " ms" << std::endl;
}

void PmergeMe::insertData(int argc, char **argv)
{
	int idx = 1;

	while (idx < argc) {
		std::string intToString(argv[idx]), tmp;
		std::stringstream stream;
		int number;

		stream.str(intToString);
		stream >> number;
		if (stream.fail() || number < 0)
			throw std::invalid_argument(std::string("Error"));
		stream >> tmp;
		if (!tmp.empty())
			throw std::invalid_argument(std::string("Error"));
		if (find(this->sortedVector.begin(), this->sortedVector.end(), number) != this->sortedVector.end())
			throw std::invalid_argument(std::string("Error"));
		this->sortedVector.push_back(number);
		this->sortedList.push_back(number);
		idx++;
	}
}

void PmergeMe::printData()
{
	int size = static_cast<int>(this->sortedVector.size());

	for (int idx = 0; idx < size; idx++)
		std::cout << this->sortedVector[idx] << ' ';
	std::cout << std::endl;
}

double PmergeMe::sortVector()
{
	std::clock_t startVector = std::clock();
	
	return static_cast<double>(std::clock()) - startVector;
}

double PmergeMe::sortList()
{
	std::clock_t startList = std::clock();

	return static_cast<double>(std::clock()) - startList;
}
