#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal("Dog")
{
	*this = copy;
	std::cout << "Dog default copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog default destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Dog default assignment operator called" << std::endl;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "~~Dog jazz~~\n" << std::endl;
}

std::string	Dog::GetType(void) const
{
	return type;
}

Brain		*Dog::GetBrain(void) const
{
	return _brain;
}
