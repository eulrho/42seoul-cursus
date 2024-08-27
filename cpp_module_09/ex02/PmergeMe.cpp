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
		this->vector = std::vector<NumberPairVector>(other.vector);
		this->list = std::list<NumberPairList>(other.list);
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

		NumberPairVector v;
		NumberPairList l;

		v.number = number;
		l.number = number;
		if (findVector(this->vector.begin(), this->vector.end(), v) != this->vector.end())
			throw std::invalid_argument(std::string("Error"));
		this->vector.push_back(v);
		this->list.push_back(l);
		idx++;
	}
}

PmergeMe::vectorPairIter PmergeMe::findVector(vectorPairIter begin, vectorPairIter end, const NumberPairVector &target)
{
	vectorPairIter iter = begin;

	for (; iter != end; iter++) {
		if (iter->number == target.number)
			break ;
	}
	return iter;
}

double PmergeMe::sortVector()
{
	std::clock_t startVector = std::clock();

	int isOdd = this->vector.size() % 2 == 1;
	int size = this->vector.size() - isOdd;

	std::vector<NumberPairVector> vectorPair, bottom;

	for (int i=0; i<size; i+=2) {
		NumberPairVector mainChain;

		if (this->vector[i].number > this->vector[i + 1].number) {
			mainChain = this->vector[i];
			mainChain.pair.push_back(this->vector[i + 1]);
		}
		else {
			mainChain = this->vector[i + 1];
			mainChain.pair.push_back(this->vector[i]);
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
	if (isOdd)
		bottom.push_back(*(this->vector.end() - 1));

	this->vector = topBottomSortVector(vectorPair, bottom);
	return static_cast<double>(std::clock()) - startVector;
}

void PmergeMe::recursiveSortVector(std::vector<NumberPairVector> &vectorPair)
{
	int isOdd = vectorPair.size() % 2 == 1;
	int size = vectorPair.size() - isOdd;

	std::vector<NumberPairVector> newVectorPair, bottom;

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

std::vector<PmergeMe::NumberPairVector> PmergeMe::topBottomSortVector(std::vector<NumberPairVector> &top, std::vector<NumberPairVector> &bottom)
{
	std::vector<NumberPairVector> res;
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
			iter = std::upper_bound(res.begin(), res.end(), bottom[start], compare);
			res.insert(iter, bottom[start]);
			start--;
		}
		n++;
	}
	return res;
}

bool PmergeMe::compare(const NumberPairVector &a, const NumberPairVector &b)
{
	return a.number < b.number;
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
