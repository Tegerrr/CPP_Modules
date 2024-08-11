#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string	otherType)
{
	type = otherType;
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	*this = copy;
	std::cout << "WrongAnimal default copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "WrongAnimal default assignment operator called" << std::endl;
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "~~WrongAnimal jazz~~\n" << std::endl;
}
