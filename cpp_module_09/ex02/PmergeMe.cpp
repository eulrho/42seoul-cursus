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
		this->vector = std::vector<int>(other.vector);
		this->list = std::list<int>(other.list);
		this->timeOfVector = other.timeOfVector;
		this->timeOfList = other.timeOfList;
	}
	return *this;
}

void PmergeMe::fordJohnson(int argc, char **argv)
{
	insertData(argc, argv);

	std::cout << "Before:	";
	printData(this->vector);

	this->timeOfVector = sortVector();
	this->timeOfList = sortList();

	std::cout << "After:	";
	printData(this->vector);
	// printData(this->list);

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
		if (find(this->vector.begin(), this->vector.end(), number) != this->vector.end())
			throw std::invalid_argument(std::string("Error"));
		this->vector.push_back(number);
		this->list.push_back(number);
		idx++;
	}
}

double PmergeMe::sortVector()
{
	std::clock_t startVector = std::clock();

	std::vector<int> sortedVector;
	int isOdd = this->vector.size() % 2 == 1;
	int size = this->vector.size() - isOdd;

	std::vector<NumberPair> vectorPair, bottom;

	for (int i=0; i<size; i+=2) {
		NumberPair mainChain, subChain;

		if (this->vector[i] > this->vector[i + 1]) {
			mainChain.number = this->vector[i];
			subChain.number = this->vector[i + 1];
			mainChain.pair.push_back(subChain);
		}
		else {
			mainChain.number = this->vector[i + 1];
			subChain.number = this->vector[i];
			mainChain.pair.push_back(subChain);
		}
		vectorPair.push_back(mainChain);
	}

	if (this->vector.size() >= 2)
		recursiveSortVector(vectorPair);
	size = static_cast<int>(vectorPair.size());
	for (int i=0; i<size; i++) {
		bottom.push_back(*(vectorPair[i].pair.end() - 1));
		vectorPair[i].pair.pop_back();
	}
	if (isOdd) {
		NumberPair tmp;

		tmp.number = *(this->vector.end() - 1);
		bottom.push_back(tmp);
	};

	std::vector<NumberPair> tmp = topBottomSortVector(vectorPair, bottom);

	this->vector = extractVector(tmp);
	return static_cast<double>(std::clock()) - startVector;
}

void PmergeMe::recursiveSortVector(std::vector<NumberPair> &vectorPair)
{
	int isOdd = vectorPair.size() % 2 == 1;
	int size = vectorPair.size() - isOdd;

	std::vector<NumberPair> newVectorPair, bottom;

	for (int i=0; i<size; i+=2) {
		if (vectorPair[i].number > vectorPair[i + 1].number) {
			newVectorPair.push_back(vectorPair[i]);
			newVectorPair[i / 2].pair.push_back(vectorPair[i + 1]);
		}
		else {
			newVectorPair.push_back(vectorPair[i + 1]);
			newVectorPair[i / 2].pair.push_back(vectorPair[i]);
		}
	}

	if (newVectorPair.size() >= 2)
		recursiveSortVector(newVectorPair);

	size = static_cast<int>(newVectorPair.size());
	for (int i=0; i<size; i++)
	{
		bottom.push_back(*(newVectorPair[i].pair.end() - 1));
		newVectorPair[i].pair.pop_back();
	}
	if (isOdd) bottom.push_back(*(vectorPair.end() - 1));

	vectorPair = topBottomSortVector(newVectorPair, bottom);
}

std::vector<PmergeMe::NumberPair> PmergeMe::topBottomSortVector(std::vector<NumberPair> &top, std::vector<NumberPair> &bottom)
{
	std::vector<NumberPair> res;
	std::vector<int> jacobsthalNumber;
	int n = 2, idx=0, size = static_cast<int>(bottom.size());

	res = top;

	jacobsthalNumber.push_back(0);
	jacobsthalNumber.push_back(1);

	while (idx < size) {
		insertNewJacobsthalNumber(jacobsthalNumber, n);
		
		int start = jacobsthalNumber[n] - 1, end = idx;
		vectorPairIter iter;

		if (start >= size) start = size - 1;
		idx = start + 1;
		while (start >= end) {
			iter = searchPosition(res.begin(), res.end(), bottom[start], compare);
			res.insert(iter, bottom[start]);
			start--;
		}
		n++;
	}
	return res;
}

bool PmergeMe::compare(const NumberPair &a, const NumberPair &b)
{
	return a.number < b.number;
}

std::vector<int> PmergeMe::extractVector(std::vector<NumberPair> &vectorPair)
{
	std::vector<int> res;
	vectorPairIter iter = vectorPair.begin();

	for (; iter != vectorPair.end(); iter++)
		res.push_back(iter->number);
	return res;
}

void PmergeMe::insertNewJacobsthalNumber(std::vector<int> &jacobsthalNumber, int n)
{
	jacobsthalNumber.push_back(jacobsthalNumber[n - 1] + 2 * jacobsthalNumber[n - 2]);
}

double PmergeMe::sortList()
{
	std::clock_t startList = std::clock();
	//std::list<int> sortedList;

	//this->list = sortedList;
	return static_cast<double>(std::clock()) - startList;
}
