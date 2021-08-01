/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:58:59 by mmizuno           #+#    #+#             */
/*   Updated: 2021/08/01 07:45:44 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// ================================= const ================================== //

# define MSG_USAGE_DESCRIPTION		"./phonebook (need not argument)"
# define MSG_ERR_FAIL_READ_COMMAND	"Fail to read COMMAND !!"

// --------------------------------- color ---------------------------------- //

# define ESC_RESET					"\033[0m"
# define ESC_FNT_BOLD				"\033[1m"
# define ESC_CLR_RED				"\033[38;5;01m"
# define ESC_CLR_GREEN				"\033[38;5;02m"
# define ESC_CLR_CYAN				"\033[38;5;06m"

// ================================ library ================================= //

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

#include "contacts.hpp"

// ========================= prototype declaration ========================== //


// ========================================================================== //

#endif
