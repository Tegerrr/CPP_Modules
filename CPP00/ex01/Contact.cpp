/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:57:55 by mac               #+#    #+#             */
/*   Updated: 2024/05/06 19:23:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

	void		Contact::SetFirstName(std::string str)
	{
		int flag;

		while (1)
		{
			flag = 0;
			std::cout << "First Name: ";
			getline(std::cin, str, '\n');
			for (int i = 0; str[i]; i++)
			{
				if (isspace(str[i]) || !isalpha(str[i]))
					flag = 1;
			}
			if (!str.empty() && flag == 0)
				break ;
			std::cout << "! First Name can't be empty and must contain only alphabetical characters !" << std::endl;
		}
		this->firstName = str;
	}

	void		Contact::SetLastName(std::string str)
	{
		int flag;

		while (1)
		{
			flag = 0;
			std::cout << "Last Name: ";
			getline(std::cin, str, '\n');
			for (int i = 0; str[i]; i++)
			{
				if (isspace(str[i]) || !isalpha(str[i]))
					flag = 1;
			}
			if (!str.empty() && flag == 0)
				break ;
			std::cout << "! Last Name can't be empty and must contain only alphabetical characters !" << std::endl;
		}
		this->lastName = str;
	}
	
	void		Contact::SetNickName(std::string str)
	{
		int flag;

		while (1)
		{
			flag = 0;
			std::cout << "Nickname: ";
			getline(std::cin, str, '\n');
			for (int i = 0; str[i]; i++)
			{
				if (isspace(str[i]) || !isalpha(str[i]))
					flag = 1;
			}
			if (!str.empty() && flag == 0)
				break ;
			std::cout << "! Nickname can't be empty and must contain only alphabetical characters !" << std::endl;
		}
		this->nickName = str;
	}
	
	void		Contact::SetPhoneNumber(std::string str)
	{
		int flag;

		while (1)
		{
			flag = 0;
			std::cout << "Phone Number: ";
			getline(std::cin, str, '\n');
			for (int i = 0; str[i]; i++)
			{
				if (isspace(str[i]) || !isdigit(str[i]))
					flag = 1;
			}
			if (!str.empty() && flag == 0)
				break ;
			std::cout << "! Phone Number can't be empty and must contain only numeric characters !" << std::endl;
		}
		this->phoneNumber = str;
	}
	
	void		Contact::SetDarkestSecret(std::string str)
	{
		int flag;

		while (1)
		{
			flag = 0;
			std::cout << "Darkest Secret: ";
			getline(std::cin, str, '\n');
			for (int i = 0; str[i]; i++)
			{
				if (isdigit(str[i]) || isalpha(str[i]))
					flag = 1;
			}
			if (!str.empty() && flag == 1)
				break ;
			std::cout << "! Darkest Secret can't be empty !" << std::endl;
		}
		this->darkestSecret = str;
	}

	std::string	Contact::GetFirstName(void)
	{
		
		return (this->firstName);
	}
	
	std::string	Contact::GetLastName(void)
	{
		return (this->lastName);
	}
	
	std::string	Contact::GetNickName(void)
	{
		return (this->nickName);
	}
	
	std::string	Contact::GetPhoneNumber(void)
	{
		return (this->phoneNumber);
	}
	
	std::string	Contact::GetDarkestSecret(void)
	{
		return (this->darkestSecret);
	}
	