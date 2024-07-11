/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:56:46 by mac               #+#    #+#             */
/*   Updated: 2024/05/13 13:56:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	StackZombie("Stack Zombie");
	StackZombie.announce();
	Zombie	*HeapZombie = newZombie("Heap Zombie");
	HeapZombie->announce();
	randomChump("Random Zombie");
	delete HeapZombie;
	return 0;
}