/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:33:21 by mac               #+#    #+#             */
/*   Updated: 2024/05/06 19:27:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

const int MAX_CONTACTS = 8;
const int COLUMN_LIMIT = 10;

class PhoneBook
{
	private:
		Contact		phonebook[MAX_CONTACTS];

	public:
		void		command_add(int);
		void		command_search(int);
};

#endif