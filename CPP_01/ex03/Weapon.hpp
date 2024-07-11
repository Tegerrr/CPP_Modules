/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:28:10 by mac               #+#    #+#             */
/*   Updated: 2024/05/27 19:46:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string _type);
		void		setType(std::string weapon);
		std::string	getType(void);
};

#endif
