#include "Animal.hpp"

Animal::Animal(void)
{
	type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string	otherType)
{
	type = otherType;
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
	std::cout << "Animal default copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal default assignment operator called" << std::endl;
	return *this;
}

std::string	Animal::getType(void) const
{
	return type;
}

void	Animal::makeSound(void) const
{
	if (type == "Cat")
		std::cout << "~~Cat jazz~~\n" << std::endl;
	else if (type == "Dog")
		std::cout << "~~Dog jazz~~\n" << std::endl;
	else
		std::cout << "~~Animal jazz~~\n" << std::endl;
}
