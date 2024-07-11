/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:08:35 by mac               #+#    #+#             */
/*   Updated: 2024/05/26 18:52:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "brain memory address:		" << &brain << std::endl;
	std::cout << "address of stringPTR:		" << stringPTR << std::endl;
	std::cout << "address of stringREF:		" << &stringREF << std::endl;

	std::cout << "value of brain:			" << brain << std::endl;
	std::cout << "what stringPTR points to:	" << *stringPTR << std::endl;
	std::cout << "what stringREF points to:	" << stringREF << std::endl;
	return 0;
}
