/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:28:07 by mac               #+#    #+#             */
/*   Updated: 2024/05/27 19:34:19 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon		&_weapon;
		std::string	_name;
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
};

#endif
