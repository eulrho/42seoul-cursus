#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		this->n = other.n;
		this->v = std::vector<int> (other.v);
	}
	return *this;
}

void Span::addNumber(const int &number)
{
	if (this->v.size() == this->n)
		throw ExtraSpaceException();
	this->v.push_back(number);
}

void Span::addNumberRange(const unsigned int &range)
{
	if (this->n < range)
		throw std::out_of_range(std::string("the range is too big"));
	
	unsigned int size = this->v.size();
	for (unsigned int i = size; i < range; i++) {
		int tmp = std::rand() % 2;
		if (tmp == 0)
			this->v.push_back(std::rand());
		else this->v.push_back(std::rand() * -1);
	}
	// std::cout << "elements" << std::endl;
	// for (unsigned int i = 0; i < 10; i++) {
	// 	std::cout << this->v[i] << ' ';
	// }
	std::cout << std::endl;
}

unsigned long Span::shortestSpan()
{
	if (this->v.size() <= 1) throw TooFewException();

	std::vector<int> sorted = std::vector<int> (this->v);
	std::sort(sorted.begin(), sorted.end());
	unsigned long res = static_cast<unsigned long>(sorted[1]) - sorted[0];

	for (unsigned int i = 2; i < sorted.size(); i++) {
		unsigned long tmp = static_cast<unsigned long>(sorted[i]) - sorted[i - 1];
		//std::cout << sorted[i] << " - " << sorted[i - 1] << " = " << tmp << std::endl; 
		res = res > tmp ? tmp : res;
	}
	return res;
}

unsigned long Span::longestSpan()
{
	if (this->v.size() <= 1) throw TooFewException();

	std::vector<int> sorted = std::vector<int> (this->v);
	sort(sorted.begin(), sorted.end());
	//std::cout << sorted.back()  << ' ' << sorted.front() << '\n';
	return static_cast<unsigned long>(sorted.back()) - sorted.front();
}

const char* Span::ExtraSpaceException::what() const throw()
{
	return "there is no extra space";
}

const char* Span::TooFewException::what() const throw()
{
	return "there is no element or only one";
}
