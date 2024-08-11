/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:32:37 by mac               #+#    #+#             */
/*   Updated: 2024/05/08 13:22:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	command_loop(void);

int main()
{
	system("clear");
	std::cout << "\n* Welcome to the PhoneBook! *\n\nYou can use the following commands:\n"
		" _________________________________________________________________________\n"
		"|   ADD |                 Add a new user to the phonebook                 |\n"
		"|—————————————————————————————————————————————————————————————————————————|\n"
		"| SEARCH| See the list of contacts and select to view personal information|\n"
		"|—————————————————————————————————————————————————————————————————————————|\n"
		"|  EXIT |                    Exit and end the program                     |\n"
		" —————————————————————————————————————————————————————————————————————————\n" << std::endl;
	command_loop();
	system("clear");
	std::cout << "! You have exited your PhoneBook !\n"
				 "        All data is GONE            " << std::endl;
	return 0;
}
