/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:52:15 by mmizuno           #+#    #+#             */
/*   Updated: 2021/08/01 19:50:48 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

// ======================== constructor / destructor ======================== //

Contact::Contact(void)
{
	initFields();
}

// -------------------------------------------------------------------------- //

Contact::~Contact()
{
}

// ======================= public method (initFields) ======================= //

/*!
** @brief	initialize field data
** @param	none
** @return	none
*/
void Contact::initFields()
{
	_contactID = 0;
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_login = "";
	_postalAddress = "";
	_emailAddress = "";
	_phoneNumber = "";
	_birthdayDate = "";
	_favoriteMeal = "";
	_underwearColor = "";
	_darkestSecret = "";
}

// ======================= public method (setFields) ======================== //

/*!
** @brief	set field data
** @param	fieldName	contact field name (by value)
** @param	fieldData	contact field data (by reference)
** @return	none
*/
void Contact::_setField(std::string fieldName, std::string &fieldData)
{
	// print prompt
	std::cout << ESC_FNT_BOLD ESC_CLR_YELLOW << "Enter your " << fieldName << " > " << ESC_RESET;
	// read data from stdin
	std::getline(std::cin, fieldData);
	if (std::cin.fail()) {
		std::cout << ESC_FNT_BOLD ESC_CLR_RED << MSG_ERR_FAIL_READ_DATA << ESC_RESET << std::endl;
		exit(EXIT_FAILURE);
	}
}

// -------------------------------------------------------------------------- //

/*!
** @brief	set all field data
** @param	contactID	contact ID number (unique number)
** @return	none
*/
void Contact::setFields(int contactID)
{
	_contactID = contactID;
	_setField("FIRST NAME", _firstName);
	_setField("LAST NAME", _lastName);
	_setField("NICK NAME", _nickname);
	_setField("LOGIN", _login);
	_setField("POSTAL ADDRESS", _postalAddress);
	_setField("E-MAIL ADDRESS", _emailAddress);
	_setField("PHONE NUMBER", _phoneNumber);
	_setField("BIRTHDAY DATE", _birthdayDate);
	_setField("FAVORITE MEAL", _favoriteMeal);
	_setField("UNDERWEAR COLOR", _underwearColor);
	_setField("DARKEST SECRET", _darkestSecret);
}

// ====================== public method (printFields) ======================= //

/*!
** @brief	print field data
** @param	fieldName	contact field name
** @param	fieldData	contact field data
** @return	none
*/
void Contact::_printField(std::string fieldName, std::string fieldData)
{
	std::cout << ESC_FNT_BOLD ESC_CLR_YELLOW << fieldName;
	std::cout << " : " << ESC_RESET;
	std::cout << fieldData;
	std::cout << std::endl;
}

// -------------------------------------------------------------------------- //

/*!
** @brief	print all field data
** @param	none
** @return	none
*/
void Contact::printFields()
{
	// _printField("ID             ", std::to_string( _contactID));	// for debug
	_printField("FIRST NAME     ", _firstName);
	_printField("LAST NAME      ", _lastName);
	_printField("NICK NAME      ", _nickname);
	_printField("LOGIN          ", _login);
	_printField("POSTAL ADDRESS ", _postalAddress);
	_printField("E-MAIL ADDRESS ", _emailAddress);
	_printField("PHONE NUMBER   ", _phoneNumber);
	_printField("BIRTHDAY DATE  ", _birthdayDate);
	_printField("FAVORITE MEAL  ", _favoriteMeal);
	_printField("UNDERWEAR COLOR", _underwearColor);
	_printField("DARKEST SECRET ", _darkestSecret);
}

// ================= public method (_printFieldForSearch) =================== //

/*!
** @brief	print field data for search (adjust string size)
** @param	fieldData	contact field data (by reference)
** @return	none
*/
void Contact::_printFieldForSearch(std::string fieldData)
{
	if (fieldData.size() <= 10)
	{
		std::cout << std::setw(10) << std::right << std::setfill(' ') << fieldData;
	}
	else
	{
		fieldData.resize(9);
		std::cout << fieldData << ".";
	}
}

// -------------------------------------------------------------------------- //

/*!
** @brief	print all field data for search (adjust string size)
** @param	index	contact index number (in class "contacts", apply index number because class "contact" used for array)
** @return	none
*/
void Contact::printFieldsForSearch(int index)
{
	// is data exist?
	if (!_contactID) {
		return;
	}
	// print contact field data for search
	std::cout << "|";
	_printFieldForSearch(std::to_string(index));
	std::cout << "|";
	_printFieldForSearch(_firstName);
	std::cout << "|";
	_printFieldForSearch(_lastName);
	std::cout << "|";
	_printFieldForSearch(_nickname);
	std::cout << "|" << std::endl;
}

// ============================= setter / getter ============================ //

int Contact::getContactID()
{
	return (_contactID);
}

// ========================================================================== //
