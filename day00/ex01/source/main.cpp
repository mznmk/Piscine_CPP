/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:41:18 by mmizuno           #+#    #+#             */
/*   Updated: 2021/08/01 14:16:37 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

// ========================================================================== //

/*!
** @brief	printTitle (ascii art)
** @param	none
** @return	none
*/
void printTitle()
{
	std::cout << ESC_FNT_BOLD ESC_CLR_CYAN << R"(
____  _                      ____              _    
|  _ \| |__   ___  _ __   ___| __ )  ___   ___ | | __
| |_) | '_ \ / _ \| '_ \ / _ \  _ \ / _ \ / _ \| |/ /
|  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < 
|_|   |_| |_|\___/|_| |_|\___|____/ \___/ \___/|_|\_\

)" << ESC_RESET;
}

// ========================================================================== //

/*!
** @brief	read command (main loop)
** @param	none
** @return	none
*/
void	readCommand(void)
{
	std::string		command;
	Contacts		c;

	while (42)
	{
		// print prompt
		std::cout << ESC_FNT_BOLD ESC_CLR_GREEN << "phonebook > " << ESC_RESET;
		// read command from stdin
		std::getline(std::cin, command);
		if (std::cin.fail()) {
			std::cout << ESC_FNT_BOLD ESC_CLR_RED << MSG_ERR_FAIL_READ_COMMAND << ESC_RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		// execute command
		if (command == "ADD")
		{
			// execute "ADD" command
			c.addContact();
		}
		else if (command == "SEARCH")
		{
			// execute "SEARCH" command
			c.searchContact();
		}
		else if (command == "EXIT")
		{
			// execute "EXIT" command (exit loop)
			break;
		}
		// else if (command == "PRINT")
		// {
		// 	// execute "PRINT" command (for debug)
		// 	c.printContacts();
		// }
	}
}

// -------------------------------------------------------------------------- //

/*!
** @brief	main (entry point)
** @param	argc	argument count
** @param	argv	argument contents
** @return	status
*/
int	main(int argc, char **argv) {
	// check argument
	(void)argv;
	if (argc != 1){
		std::cout << ESC_FNT_BOLD ESC_CLR_RED << MSG_USAGE_DESCRIPTION << ESC_RESET << std::endl;
		return (EXIT_FAILURE);
	}
	// print title (ascii art)
	printTitle();
	// start loop (read command)
	readCommand();
	// return
	return (EXIT_SUCCESS);
}

// ========================================================================== //
