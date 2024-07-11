#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
	*this = copy;
	std::cout << "WrongCat default copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "WrongCat default assignment operator called" << std::endl;
	return *this;
}
