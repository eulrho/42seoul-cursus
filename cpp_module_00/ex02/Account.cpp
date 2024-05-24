#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void ) {}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t timer = std::time(NULL);
	struct tm *t = std::localtime(&timer);

	std::cout << "[";
	std::cout << t->tm_year + 1900;
	if (t->tm_mon < 10)
		std::cout << "0";
	std::cout << t->tm_mon;
	if (t->tm_mday < 10)
		std::cout << "0";
	std::cout << t->tm_mday << "_";
	if (t->tm_hour < 10)
		std::cout << "0";
	std::cout << t->tm_hour;	
	if (t->tm_min < 10)
		std::cout << "0";
	std::cout << t->tm_min;
	if (t->tm_sec < 10)
		std::cout << "0";
	std::cout << t->tm_sec;
	std::cout << "] ";
}

int	Account::getNbAccounts( void ) {return _nbAccounts;}

int	Account::getTotalAmount( void ) {return _totalAmount;}

int	Account::getNbDeposits( void ) {return _totalNbDeposits;}

int	Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	std::cout << "deposit:" << deposit << ';';
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << checkAmount() << ';';
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	bool status = 1;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	if (checkAmount() < withdrawal)
		std::cout << "withdrawal:refused";
	else {
		std::cout << "withdrawal:" << withdrawal << ';';
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "amount:" << checkAmount() << ';';
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
		status = 0;
	}
	std::cout << std::endl;
	return status;
}

int		Account::checkAmount( void ) const {return _amount;}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
