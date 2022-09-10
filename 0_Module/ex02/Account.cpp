#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

static void printTwo(int input)
{
    if (input < 10)
    {
        std::cout << '0';
    }
    std::cout << input;
}

void	Account::_displayTimestamp( void )
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);

    std::cout << "[";
    std::cout << now->tm_year + 1900;
    printTwo((now->tm_mon) + 1);
    printTwo(now->tm_mday);
    std::cout << "_";
    printTwo(now->tm_hour);
    printTwo(now->tm_min);
    printTwo(now->tm_sec);
    std::cout << "] ";
}

Account::Account( void )
{
    _accountIndex = _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"; 
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::Account( int initial_deposit )
{
    _totalAmount += initial_deposit;
    
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"; 
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"; 
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
    _totalAmount -= _amount;
    _nbAccounts--;
}

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void    Account::makeDeposit( int deposit)
{
    _nbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"; 
    std::cout << "p_amount:" << _amount << ";";
    _amount += deposit;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;

    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"; 
    std::cout << "p_amount:" << _amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    _amount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return true;
}

void    Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"; 
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

int     Account::checkAmount( void ) const
{
    return (_amount);
}
