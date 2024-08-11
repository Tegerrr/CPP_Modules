#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	*this = copy;
	std::cout << "Cat default copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "~~Cat jazz~~" << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Cat default assignment operator called" << std::endl;
	return *this;
}
