/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:14:00 by mac               #+#    #+#             */
/*   Updated: 2024/05/08 13:28:05 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	get_index(void)
{
	std::string	buffer;

	while (1)
	{
		std::cout << "\nChoose a contact index: ";
		getline(std::cin, buffer, '\n');
		if (buffer.find_first_not_of("0123456789") && !buffer.empty() && buffer.length() == 1)
			break ;
		std::cout << "* Index not found :O *\n" << std::endl;
	}
	return (stoi(buffer));
}

void	truncate_data(Contact *phonebook, std::string *firstName, std::string *lastName, std::string *nickName, int n)
{
	if (phonebook->GetFirstName().length() > (COLUMN_LIMIT - 1))
	{
		(std::istringstream) phonebook[n].GetFirstName() >> std::setw(COLUMN_LIMIT - 1) >> *firstName;
		*firstName += ".";
	}
	else
		(std::istringstream) phonebook[n].GetFirstName() >> std::setw(COLUMN_LIMIT) >> *firstName;
	if (phonebook->GetLastName().length() > (COLUMN_LIMIT - 1))
	{
		(std::istringstream) phonebook[n].GetLastName() >> std::setw(COLUMN_LIMIT - 1) >> *lastName;
		*lastName += ".";
	}
	else
		(std::istringstream) phonebook[n].GetLastName() >> std::setw(COLUMN_LIMIT) >> *lastName;
	if (phonebook->GetNickName().length() > (COLUMN_LIMIT - 1))
	{
		(std::istringstream) phonebook[n].GetNickName() >> std::setw(COLUMN_LIMIT - 1) >> *nickName;
		*nickName += ".";
	}
	else
		(std::istringstream) phonebook[n].GetNickName() >> std::setw(COLUMN_LIMIT) >> *nickName;
}

void	choose_contact(Contact *phonebook, int amountOfContacts)
{
	int			contactInd;

	if (amountOfContacts > MAX_CONTACTS)
		amountOfContacts = MAX_CONTACTS;
	while (1)
	{
		contactInd = get_index();
		std::cout << std::endl;
		if (std::cin.good() && contactInd >= 0 && contactInd < amountOfContacts)
		{
			std::cout << "First Name: " << phonebook[contactInd].GetFirstName() << std::endl;
			std::cout << "Last Name: " << phonebook[contactInd].GetLastName() << std::endl;
			std::cout << "Nickname: " << phonebook[contactInd].GetNickName() << std::endl;
			std::cout << "Phone Number: " << phonebook[contactInd].GetPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << phonebook[contactInd].GetDarkestSecret() << std::endl;
			break;
		}
		else
		{
			std::cin.clear();
			std::cout << "* Index not found :O *\n" << std::endl;
		}
	}
}

void	command_loop(void)
{
	PhoneBook		phbook;
	std::string		command;
	int				i = 0;

	while (1)
	{		
		std::cout << "\nEnter a command > ";
		std::cin.clear();
		getline(std::cin, command, '\n');
		if (command == "ADD")
			phbook.command_add(i++%MAX_CONTACTS);
		else if (command == "SEARCH")
			phbook.command_search(i);
		else if (command == "EXIT")
			break ;
	}
}
