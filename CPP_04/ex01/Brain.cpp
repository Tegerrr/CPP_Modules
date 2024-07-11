#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Brain default copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain default assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return *this;
}

std::string	*Brain::GetIdeas(void)
{
	return ideas;
}
