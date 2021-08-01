/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:52:01 by mmizuno           #+#    #+#             */
/*   Updated: 2021/08/01 14:15:32 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

// ================================= const ================================== //

# define MSG_ERR_FAIL_READ_DATA		"Fail to read DATA !!"

// --------------------------------- color ---------------------------------- //

# define ESC_RESET					"\033[0m"
# define ESC_FNT_BOLD				"\033[1m"
# define ESC_CLR_RED				"\033[38;5;01m"
# define ESC_CLR_YELLOW				"\033[38;5;03m"

// ================================ library ================================= //

# include <iostream>
# include <iomanip>
# include <string>

// ================================= class ================================== //

class Contact
{
	private:
		// variable
		int				_contactID;
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_login;
		std::string		_postalAddress;
		std::string		_emailAddress;
		std::string		_phoneNumber;
		std::string		_birthdayDate;
		std::string		_favoriteMeal;
		std::string		_underwearColor;
		std::string		_darkestSecret;
		// method
		void			_setField(std::string fieldName, std::string &fieldData);
		void			_printField(std::string fieldName, std::string fieldData);
		void			_printFieldForSearch(std::string fieldData);
	public:
		// constructor / destructor
		Contact();
		virtual ~Contact();
		// method
		void			initFields();
		void			setFields(int contactID);
		void			printFields();
		void			printFieldsForSearch(int index);
		// getter / setter
		int				getContactID();
};

// ========================================================================== //

#endif
