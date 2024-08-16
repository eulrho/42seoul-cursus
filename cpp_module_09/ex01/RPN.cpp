#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other) {
		this->stack = std::stack<float>(other.stack);
	}
	return *this;
}

void RPN::postfix(const std::string &input)
{
	float tmp;
	std::size_t idx = 0, len = input.length(), start;

	while (idx < len) {
		while (idx < len && std::isspace(input[idx])) idx++;
		if (idx == len) break ;

		start = idx;
		while (idx < len && !std::isspace(input[idx])) idx++;

		if (idx - start == 1 && (!std::isdigit(input[start]))) {
			switch (input[start]) {
				case '+':
					this->add();
					break ;
				case '-':
					this->sub();
					break ;
				case '*':
					this->mult();
					break ;
				case '/':
					this->div();
					break ;
				default :
					throw std::invalid_argument(std::string("Error"));
			}
		}
		else {
			std::stringstream stream;
			stream.str(input.substr(start, idx - start));
			stream >> tmp;
			if (stream.fail() || tmp < 0.0 || tmp > 10.0)
				throw std::invalid_argument(std::string("Error"));
			this->stack.push(tmp);
		}
	}
	if (this->stack.size() != 1) throw std::invalid_argument(std::string("Error"));

	std::cout << this->stack.top() << std::endl;
}

void RPN::add()
{
	if (this->stack.size() < 2)
		throw std::invalid_argument(std::string("Error"));
	
	float res, tmp = this->stack.top();
	
	this->stack.pop();
	res = this->stack.top() + tmp;
	this->stack.pop();
	this->stack.push(res);
}
void RPN::sub()
{
	if (this->stack.size() < 2)
		throw std::invalid_argument(std::string("Error"));
	
	float res, tmp = this->stack.top();
	
	this->stack.pop();
	res = this->stack.top() - tmp;
	this->stack.pop();
	this->stack.push(res);
}

void RPN::mult()
{
	if (this->stack.size() < 2)
		throw std::invalid_argument(std::string("Error"));

	float res, tmp = this->stack.top();
	
	this->stack.pop();
	res = this->stack.top() * tmp;
	this->stack.pop();
	this->stack.push(res);
}

void RPN::div()
{
	if (this->stack.size() < 2)
		throw std::invalid_argument(std::string("Error"));

	float res, tmp = this->stack.top();
	
	this->stack.pop();
	res = this->stack.top() / tmp;
	this->stack.pop();
	this->stack.push(res);
}
