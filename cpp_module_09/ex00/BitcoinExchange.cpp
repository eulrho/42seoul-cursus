#include <iostream>
#include <sstream>
#include <cctype>
#include <fstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		this->data = std::map<std::string, float>(other.data);
	}
	return *this;
}

void BitcoinExchange::findAmountOfBitcoin(const std::string &fileName)
{
	try {
		insertData("data.csv");
		printAmountOfBitcoin(fileName);
	}
	catch(std::string &str) {
		std::cout << "Error: invalid csv file data => " << str << std::endl;
		return ;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	
}

void BitcoinExchange::insertData(const std::string &fileName)
{
	std::ifstream f;

	f.open(fileName.c_str());
	if (!f.is_open()) throw FileOpenException();

	std::string line;

	std::getline(f, line);
	if (line != "date,exchange_rate")
		throw std::string("did not exist column name");
	while (!f.eof()) {
		std::getline(f, line);
		std::size_t pos = line.find(",");
		if (pos == 0 || pos == std::string::npos || pos == line.length() - 1)
			throw line;

		std::string date = line.substr(0, pos);
		std::string rate = line.substr(pos + 1);
		if (!isValidDate(date)) throw date;
		if (this->data.find(date) != this->data.end()) throw std::string("duplicate date");
		this->data.insert(std::pair<std::string, float>(date, extractRate(rate)));
	}
	f.close();
	if (this->data.empty()) throw std::string("empty file");
}

void BitcoinExchange::printAmountOfBitcoin(const std::string &fileName)
{
	std::ifstream f;

	f.open(fileName.c_str());
	if (!f.is_open()) throw FileOpenException();

	std::string line;
	float result;

	std::getline(f, line);
	if (line != "date | value")
		std::cout << "Error: did not exist column name" << std::endl;

	while (!f.eof()) {
		try {
			std::getline(f, line);

			std::size_t pos = line.find(" | ");
			if (pos == 0 || pos == std::string::npos || pos == line.length() - 3)
				throw line;

			std::string date = line.substr(0, pos);
			std::string value = line.substr(pos + 3);

			if (!isValidDate(date)) throw date;
			else result = findRate(date) * extractValue(value);
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch(std::string &str) {
			std::cout << "Error: bad input => " << str << std::endl;
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	f.close();
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	std::string str[3];
	int idx = 0;
	std::size_t pos = date.find("-"), start=0;

	while (pos != std::string::npos) {
		if (start == pos || idx == 2) return false;

		std::size_t size = pos - start;

		str[idx] = date.substr(start, size);
		start = pos + 1;
		pos = date.find("-", start);
		idx++;
	}
	if (idx == 2 && start == date.length() - 2)
		str[idx] = date.substr(start, 2);
	else return false;

	std::stringstream stream;
	bool isLeepYear = false, isThirtyOneDays = false, isFebruary = false;

	if (!isValidYear(str[0], isLeepYear)) return false;
	if (!isValidMonth(str[1], isThirtyOneDays, isFebruary)) return false;
	if (!isValidDay(str[2], isThirtyOneDays, isFebruary, isLeepYear)) return false;
	return true;
}

bool BitcoinExchange::isValidYear(const std::string &year, bool &isLeepYear)
{
	std::stringstream stream;
	std::size_t strIdx = 0, len = year.length();
	int tmp;

	if (len != 4) return false;
	while (strIdx < len && std::isdigit(year[strIdx])) strIdx++;
	if (strIdx != len) return false;
	stream.str(year);
	stream >> tmp;

	if (stream.fail()) return false;
	if ((tmp % 4 == 0 && tmp % 100 != 0) || tmp % 400 == 0)
		isLeepYear = true;
	return true;
}

bool BitcoinExchange::isValidMonth(const std::string &month, bool &isThirtyOneDays, bool &isFebruary)
{
	std::stringstream stream;
	std::size_t strIdx = 0, len = month.length();
	int tmp;

	if (len != 2) return false;
	while (strIdx < len && std::isdigit(month[strIdx])) strIdx++;
	if (strIdx != len) return false;
	stream.str(month);
	stream >> tmp;

	if (stream.fail()) return false;
	if (tmp > 12 || tmp < 1) return false;
	if (tmp == 1 || tmp == 3 || tmp == 5 || tmp == 7 || tmp == 8 || tmp == 10 || tmp == 12)
		isThirtyOneDays = true;
	if (tmp == 2) isFebruary = true;
	return true;
}

bool BitcoinExchange::isValidDay(const std::string &day, const bool &isThirtyOneDays, const bool &isFebruary, const bool &isLeepYear)
{
	std::stringstream stream;
	std::size_t strIdx = 0, len = day.length();
	int tmp;

	if (len != 2) return false;
	while (strIdx < len && std::isdigit(day[strIdx])) strIdx++;
	if (strIdx != len) return false;
	stream.str(day);
	stream >> tmp;

	if (stream.fail()) return false;
	if (tmp == 0) return false;
	if (isThirtyOneDays) {
		if (tmp > 31) return false;
	}
	else if (isFebruary) {
		if (!(tmp <= 28 || (isLeepYear && tmp == 29))) return false;
	}
	else if (tmp > 30) return false;
	return true;
}

float BitcoinExchange::extractRate(std::string &rate)
{
	std::stringstream stream;
	std::size_t dPos = rate.find(".");
	float res;

	stream.str(rate);
	if (dPos == std::string::npos) {
		int tmp;
		stream >> tmp;
		if (stream.fail()) throw rate;

		std::string str;
		stream >> str;
		if (!str.empty()) throw rate;
		res = static_cast<float>(tmp);
	}
	else {
		stream >> res;
		if (stream.fail()) throw rate;
		std::string str;
		stream >> str;
	}
	return res;
}

float BitcoinExchange::extractValue(std::string &value)
{
	std::stringstream stream;
	float res;

	stream.str(value);
	stream >> res;
	if (stream.fail()) throw TooLargeException();

	std::string str;
	stream >> str;
	
	if (res < 0) throw NegativeNumberException();
	if (res > 1000.0) throw TooLargeException();
	return res;
}

float BitcoinExchange::findRate(const std::string &date)
{
	if (this->data.find(date) != this->data.end())
		return this->data[date];
	
	std::map<std::string, float>::iterator iter;
	
	iter = this->data.lower_bound(date);
	if (iter == this->data.begin()) throw DateNotFoundException();
	iter--;
	return iter->second;
}

const char* BitcoinExchange::FileOpenException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::TooLargeException::what() const throw()
{
	return "Error: too large a number.";
}

const char* BitcoinExchange::NegativeNumberException::what() const throw()
{
	return "Error: not a positive number.";
}

const char* BitcoinExchange::DateNotFoundException::what() const throw()
{
	return "Error: could not find date";
}
