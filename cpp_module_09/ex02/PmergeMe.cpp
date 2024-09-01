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
	insertDataIntoVector(argc, argv);
	insertDataIntoList(argc, argv);

	std::cout << "Before:	";
	printData(this->vector);

	sortVector();
	sortList();

	std::cout << "After:	";
	printData(this->vector);
	// printData(this->list);

	std::cout << "Time to process a range of	" << argc - 1
		<< " elements with std::vector :	" << this->timeOfVector << " ms" << std::endl;
	std::cout << "Time to process a range of	" << argc - 1
		<< " elements with std::list :	" << this->timeOfList << " ms" << std::endl;
}

void PmergeMe::insertDataIntoVector(int argc, char **argv)
{
	std::clock_t startVector = std::clock();
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

		v.number = number;
		this->vector.push_back(v);
		idx++;
	}
	this->timeOfVector = (static_cast<double>(std::clock()) - startVector) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::insertDataIntoList(int argc, char **argv)
{
	std::clock_t startList = std::clock();
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

		NumberPairList l;

		l.number = number;
		this->list.push_back(l);
		idx++;
	}
	this->timeOfList = (static_cast<double>(std::clock()) - startList) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::sortVector()
{
	std::clock_t startVector = std::clock();

	recursiveSortVector(this->vector);
	this->timeOfVector += (static_cast<double>(std::clock()) - startVector) / CLOCKS_PER_SEC * 1000;
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
	int n = 2, idx = 0, size = static_cast<int>(bottom.size());

	res = top;

	jacobsthalNumber.push_back(0);
	jacobsthalNumber.push_back(1);

	while (idx < size) {
		insertNewJacobsthalNumberIntoVector(jacobsthalNumber, n);

		int start = jacobsthalNumber[n] - 1, end = idx;
		if (start >= size) start = size - 1;
		idx = start + 1;
		n++;

		if (start == 0) {
			res.insert(res.begin(), bottom[0]);
			continue ;
		}

		vectorPairIter resEnd = res.begin() + end * 2 + (start - end);
		while (start >= end) {
			vectorPairIter position = std::upper_bound(res.begin(), resEnd, bottom[start], compareVector);
			res.insert(position, bottom[start]);
			if (position == resEnd)
				resEnd--;
			start--;
		}
	}
	return res;
}

bool PmergeMe::compareVector(const NumberPairVector &a, const NumberPairVector &b)
{
	return a.number < b.number;
}

void PmergeMe::insertNewJacobsthalNumberIntoVector(std::vector<int> &jacobsthalNumber, int n)
{
	jacobsthalNumber.push_back(jacobsthalNumber[n - 1] + 2 * jacobsthalNumber[n - 2]);
}

void PmergeMe::sortList()
{
	std::clock_t startList = std::clock();

	recursiveSortList(this->list);
	this->timeOfList += (static_cast<double>(std::clock()) - startList) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::recursiveSortList(std::list<NumberPairList> &listPair)
{
	int isOdd = listPair.size() % 2 == 1;
	listPairIter end = listPair.end();

	std::list<NumberPairList> newListPair, bottom;

	if (isOdd) end--;
	for (listPairIter iter=listPair.begin(); iter!=end;) {
		listPairIter tmp = iter;

		if (iter->number > (++tmp)->number) {
			newListPair.push_back(*iter);
			listBack(newListPair)->pair.push_back(*tmp);
		}
		else {
			newListPair.push_back(*tmp);
			listBack(newListPair)->pair.push_back(*iter);
		}
		std::advance(iter, 2);
	}
	if (newListPair.size() >= 2)
		recursiveSortList(newListPair);

	for (listPairIter iter=newListPair.begin(); iter!=newListPair.end(); iter++)
	{
		bottom.push_back(*listBack(iter->pair));
		iter->pair.pop_back();
	}
	if (isOdd) bottom.push_back(*listBack(listPair));

	listPair = topBottomSortList(newListPair, bottom);
}

std::list<PmergeMe::NumberPairList> PmergeMe::topBottomSortList(std::list<NumberPairList> &top, std::list<NumberPairList> &bottom)
{
	std::list<NumberPairList> res;
	std::list<int> jacobsthalNumber;
	int n = 2, idx = 0, size = static_cast<int>(bottom.size());

	res = top;

	jacobsthalNumber.push_back(0);
	jacobsthalNumber.push_back(1);

	while (idx < size) {
		insertNewJacobsthalNumberIntoList(jacobsthalNumber);
		
		int start = *listBack(jacobsthalNumber) - 1, end = idx;
		if (start >= size) start = size - 1;
		idx = start + 1;
		n++;

		listPairIter startIter = bottom.begin();
		std::advance(startIter, start);
		if (start == 0) {
			res.insert(res.begin(), *startIter);
			continue ;
		}

		listPairIter resEnd = res.begin();
		std::advance(resEnd, end * 2 + (start - end));
		while (true) {
			listPairIter position = std::upper_bound(res.begin(), resEnd, *startIter, compareList);
			res.insert(position, *startIter);
			if (start == end) break ;
			if (position == resEnd)
				resEnd--;
			startIter--;
			start--;
		}
	}
	return res;
}

void PmergeMe::insertNewJacobsthalNumberIntoList(std::list<int> &jacobsthalNumber)
{
	std::list<int>::iterator back = listBack(jacobsthalNumber);

	jacobsthalNumber.push_back(*back + 2 * *(--back));
}

bool PmergeMe::compareList(const NumberPairList &a, const NumberPairList &b)
{
	return a.number < b.number;
}
