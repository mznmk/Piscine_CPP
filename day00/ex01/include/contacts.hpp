/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:53:00 by mmizuno           #+#    #+#             */
/*   Updated: 2021/08/01 14:15:37 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

// ================================= const ================================== //

# define DataCount		8

# define MSG_ERR_FAIL_READ_INDEX	"Fail to read INDEX !!"

// --------------------------------- color ---------------------------------- //

# define ESC_RESET					"\033[0m"
# define ESC_FNT_BOLD				"\033[1m"
# define ESC_CLR_RED				"\033[38;5;01m"
# define ESC_CLR_GREEN				"\033[38;5;02m"

// ================================ library ================================= //

#include "../include/contact.hpp"

// ================================= class ================================== //

class	Contacts
{
	private:
		// variable
		Contact			_contacts[DataCount];
		int				_contactsTotalCount;
		// method
		void			_initContacts();
		int				_searchWritableContact();
		void			_printContactsForSearch();
		void			_readIndexForSearch();
	public:
		// constructor / destructor
		Contacts();
		virtual ~Contacts();
		// method
		void			addContact();
		void			searchContact();
		// void			printContacts();	// for debug
};

// ========================================================================== //

#endif
