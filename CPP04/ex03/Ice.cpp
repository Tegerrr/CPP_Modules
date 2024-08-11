#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(std::string type)
{
	_type = type;
}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

Ice::Ice(Ice const &copy)
{
	*this = copy;
}

AMateria	*Ice::clone(void) const
{
	return new Ice();
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
