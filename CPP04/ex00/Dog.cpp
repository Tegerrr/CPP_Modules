#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	*this = copy;
	std::cout << "Dog default copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Dog default assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "~~Dog jazz~~" << std::endl;
}
