/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:32:50 by mac               #+#    #+#             */
/*   Updated: 2024/05/06 19:55:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <algorithm>
# include <cctype>
# include <cstring>

class Contact
{

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		void		SetFirstName(std::string);
		void		SetLastName(std::string);
		void		SetNickName(std::string);
		void		SetPhoneNumber(std::string);
		void		SetDarkestSecret(std::string);
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickName(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);

};

#endif