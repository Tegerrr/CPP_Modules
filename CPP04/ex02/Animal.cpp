#include "Animal.hpp"

Animal::Animal(void)
{
	type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
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
	if ((type == "Cat" || type == "Dog") && (other.type == "Cat" || other.type == "Dog"))
        *GetBrain() = *other.GetBrain();
    type = other.type;
	std::cout << "Animal default assignment operator called" << std::endl;
	return *this;
}

std::string	Animal::getType(void) const {return type;}

void	Animal::makeSound(void) const {}

Brain	*Animal::GetBrain(void) const {return NULL;}
