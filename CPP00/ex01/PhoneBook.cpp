/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:32:13 by mac               #+#    #+#             */
/*   Updated: 2024/05/03 18:32:14 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	truncate_string(std::string str);
void		choose_contact(Contact *phonebook, int amountOfContacts);

void	PhoneBook::command_add(int i)
{
	std::string input;

	std::cout << "Fill out the following information" << std::endl;
	this->phonebook[i].SetFirstName(input);
	this->phonebook[i].SetLastName(input);
	this->phonebook[i].SetNickName(input);
	this->phonebook[i].SetPhoneNumber(input);
	this->phonebook[i].SetDarkestSecret(input);
	system("clear");
	std::cout << "\n* A new contact has been created *\n" << std::endl;
}

void	PhoneBook::command_search(int i)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;

	if (i == 0)
	{
		std::cout << "\n* You have not created any contacts yet :O *\n" << std::endl;
		return ;
	}
	if (i > MAX_CONTACTS)
		i = MAX_CONTACTS;
	system("clear");
	std::cout <<	" ___________________________________________\n"
					"|     Index|First Name| Last Name|  Nickname|\n"
					"|——————————|——————————|——————————|——————————|\n";
	for (int n = 0; n != i; n++)
	{
		firstName = truncate_string(this->phonebook[n].GetFirstName());
		lastName = truncate_string(this->phonebook[n].GetLastName());
		nickName = truncate_string(this->phonebook[n].GetNickName());
		std::cout << "|" << std::setw(COLUMN_LIMIT) << n;
		std::cout << "|" << std::setw(COLUMN_LIMIT) << firstName;
		std::cout << "|" << std::setw(COLUMN_LIMIT) << lastName;
		std::cout << "|" << std::setw(COLUMN_LIMIT) << nickName << "|" << "\n";
	}
	std::cout <<	"|__________|__________|__________|__________|" << std::endl;
	choose_contact(this->phonebook, i);
}
