/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:52:54 by mmizuno           #+#    #+#             */
/*   Updated: 2021/08/01 14:16:30 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contacts.hpp"

// ======================== constructor / destructor ======================== //

Contacts::Contacts() : _contactsTotalCount(0)
{
	_initContacts();
}

// -------------------------------------------------------------------------- //

Contacts::~Contacts()
{
	
}

// ===================== private method (_initContacts) ===================== //

/*!
** @brief	initialize contacts (execute number of contents)
** @param	none
** @return	none
*/
void Contacts::_initContacts()
{
	for (int i = 0; i < DataCount; i++)
	{
		_contacts[i].initFields();
	}
}

// ======================= public method (addContact) ======================= //

/*!
** @brief	search writable contact (which contact is writable?)
** @param	none
** @return	writable contact index
*/
int	Contacts::_searchWritableContact()
{
	int		writableContactID;
	int		writableContactIndex;
	writableContactID = _contacts[0].getContactID();
	writableContactIndex = 0;
	for (int i = 0; i < DataCount; i++)
	{
		if (_contacts[i].getContactID() < writableContactID) {
			writableContactID = _contacts[i].getContactID();
			writableContactIndex = i;
		}
	}
	return (writableContactIndex);
}

// -------------------------------------------------------------------------- //

/*!
** @brief	add contact
** @param	none
** @return	none
*/
void Contacts::addContact()
{
	// search writable contact
	int		writableContactIndex;
	writableContactIndex = _searchWritableContact();
	// add contact (argument == contactID, != contactTotalCount)
	_contacts[writableContactIndex].setFields(_contactsTotalCount + 1);
	// set contact count
	_contactsTotalCount++;
}

// ===================== public method (searchContact) ====================== //

/*!
** @brief	print contacts for search (index / 3 kind of name)
** @param	none
** @return	none
*/
void Contacts::_printContactsForSearch()
{
	// print contact field name for search
	std::cout << "|";
	std::cout << "     Index|";
	std::cout << "FIRST NAME|";
	std::cout << " LAST NAME|";
	std::cout << " NICK NAME|";
	std::cout << std::endl;
	
	// print contact field data for search
	// (index range 1-8, not 0-7)
	for (int i = 0; i < DataCount; i++)
	{
		_contacts[i].printFieldsForSearch(i + 1);	// start index == 1
	}
}

// -------------------------------------------------------------------------- //

/*!
** @brief	read index for search
** @param	none
** @return	none
*/
void Contacts::_readIndexForSearch()
{
	// variable
	std::string		strIndex;
	int				intIndex;

	// read index until index is to be suitable value
	while (42)
	{
		// print prompt
		std::cout << ESC_FNT_BOLD ESC_CLR_GREEN << "Enter Index > " << ESC_RESET;
		// read index from stdin
		std::getline(std::cin, strIndex);
		if (std::cin.fail()) {
			std::cout << ESC_FNT_BOLD ESC_CLR_RED << MSG_ERR_FAIL_READ_INDEX << ESC_RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		// check index is empty?
		if (strIndex.empty()) {
			continue;
		}
		// convert string to int
		intIndex = std::atoi(strIndex.c_str());
		// check index is in range
		// (index range 1-8, not 0-7)
		if (1 <= intIndex && intIndex <= DataCount) {
			// print field data
			if (_contacts[intIndex - 1].getContactID())
			{
				_contacts[intIndex - 1].printFields();
				break;
			}
		} else {
			continue;
		}
	}
}

// -------------------------------------------------------------------------- //

/*!
** @brief	search contact
** @param	none
** @return	none
*/
void Contacts::searchContact()
{
	// contact exist?
	if (!_contactsTotalCount) {
		return;
	}
	// print contacts for search
	_printContactsForSearch();
	// read index
	// print field data
	_readIndexForSearch();
}

// ===================== public method (printContacts) ====================== //

// /*!
// ** @brief	print contacts (for debug)
// ** @param	none
// ** @return	none
// */
// void Contacts::printContacts()
// {
// 	for (int i = 0; i < DataCount; i++)
// 	{
// 		_contacts[i].printFields();
// 	}
// }

// ========================================================================== //
