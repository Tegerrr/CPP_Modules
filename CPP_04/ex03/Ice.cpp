#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string type)
{
	_type = type;
	std::cout << "Ice type constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice default destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
	std::cout << "Ice default assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Ice::Ice(Ice const &copy)
{
	*this = copy;
	std::cout << "Ice copy constructor called" << std::endl;
}

AMateria	*Ice::clone(void) const
{
	return new Ice(_type);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
