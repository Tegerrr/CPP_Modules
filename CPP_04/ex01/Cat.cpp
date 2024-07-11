#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal("Cat")
{
	*this = copy;
	std::cout << "Cat default copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete  _brain;
	std::cout << "Cat default destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Cat default assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "~~Cat jazz~~\n" << std::endl;
}

std::string	Cat::GetType(void) const
{
	return type;
}

Brain		*Cat::GetBrain(void) const
{
	return _brain;
}
