/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:22:05 by mmizuno           #+#    #+#             */
/*   Updated: 2021/08/01 20:26:53 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : 2021/08/01 14:22:05                           //
//                Last update : 2021/08/01 20:26:13                           //
//                Made by : Mika "Fuckin" Mizuno <mmizuno@gbu.com>            //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <iomanip>

# include "../include/Account.class.hpp"

// ============================ static variable ============================= //

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ======================== constructor / destructor ======================== //

Account::Account( int initial_deposit )
{
	// set parameter
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// display timestamp
	_displayTimestamp();

	// display status
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	// set parameter
	_nbAccounts -= 1;

	// display timestamp
	_displayTimestamp();

	// display status
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

// ========================== private constructor =========================== //

Account::Account( void )
{
	// set parameter
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// display timestamp
	_displayTimestamp();

	// display status
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

// =============== private static method (_displayTimestamp) ================ //

/*!
** @brief	display timestamp
** @param	none
** @return	none
*/
void Account::_displayTimestamp( void )
{
	// example-> [19920104_091532]
	// reference-> https://www.lisz-works.com/entry/cpp-datetime-string

	time_t		t = time(nullptr);
	const tm	*localTimePtr = localtime(&t);

	// display timestamp
	std::cout<< "[";
	std::cout
		<< std::setw(4) << std::right << std::setfill('0')
		<< localTimePtr->tm_year + 1900;
	std::cout
		<< std::setw(2) << std::right << std::setfill('0')
		<< localTimePtr->tm_mon + 1;
	std::cout
		<< std::setw(2) << std::right << std::setfill('0')
		<< localTimePtr->tm_mday;
	std::cout << "_";
	std::cout
		<< std::setw(2) << std::right << std::setfill('0')
		<< localTimePtr->tm_hour;
	std::cout
		<< std::setw(2) << std::right << std::setfill('0')
		<< localTimePtr->tm_min;
	std::cout
		<< std::setw(2) << std::right << std::setfill('0')
		<< localTimePtr->tm_sec;
	std::cout << "] ";
}

// ============== public static method (displayAccountsInfos) =============== //

/*!
** @brief	display accounts infos
** @param	none
** @return	none
*/
void Account::displayAccountsInfos( void )
{
	// display timestamp
	_displayTimestamp();

	// display accounts infos
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// ===================== public method (displayStatus) ====================== //

/*!
** @brief	display status
** @param	none
** @return	none
*/
void Account::displayStatus( void ) const
{
	// display timestamp
	_displayTimestamp();

	// display status
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

// ====================== public method (makeDeposit) ======================= //

/*!
** @brief	make and display deposit
** @param	deposit			deposit for calculate
** @return	none
*/
void Account::makeDeposit( int deposit )
{
	// display timestamp
	_displayTimestamp();

	// make and display deposit
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	// calculate amount
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	// calculate total deposit count
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

// ===================== public method (makeWithdrawal) ===================== //

/*!
** @brief	make and display withdrawal
** @param	withdrawal		withdrawal for calculate
** @return	withdrawal success / failure
*/
bool Account::makeWithdrawal( int withdrawal )
{
	// display timestamp
	_displayTimestamp();

	// make and display withdrawal
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	// withdrawal success? failure?
	if (withdrawal <= _amount)
	{
		// withdrawal success

		std::cout << "withdrawal:" << withdrawal << ";";
		// calculate amount
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "amount:" << _amount << ";";
		// calculate total withdrawal count
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	else
	{
		// withdrawal failure

		std::cout << "withdrawal:refused" << std::endl;;
		return (false);
	}

	return (true);
}

// ====================== public method (checkAmount) ======================= //

/*!
** @brief	check amount (no use ???)
** @param	none
** @return	amount
*/
int Account::checkAmount( void ) const
{
	return (_amount);
}

// ============================= setter / getter ============================ //

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

// ========================================================================== //

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
